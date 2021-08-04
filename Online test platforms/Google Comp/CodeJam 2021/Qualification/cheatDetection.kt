import java.util.*
import java.util.stream.IntStream


fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val T: Int = sc.nextInt()
    sc.nextInt()
    for (tc in 1..T) {
        val outcomes = arrayOfNulls<String>(100)
        for (i in outcomes.indices) {
            outcomes[i] = sc.next()
        }
        println(String.format("Case #%d: %d", tc, solution(outcomes)))
    }
    sc.close()
}

fun solution(outcomes: Array<String?>): Int {
    val playerCorrectNums: IntArray = Arrays.stream(outcomes)
            .mapToInt { s -> s.chars().filter { ch -> ch === '1' }.count() }
            .toArray()

    val sortedPlayers: IntArray = IntStream.range(0, 100)
            .boxed()
            .sorted(Comparator.comparing { i -> playerCorrectNums[i] })
            .mapToInt { x -> x }
            .toArray()

    val s = DoubleArray(100)

    for (i in s.indices) {
        s[sortedPlayers[i]] = -3 + 6.0 / (100 - 1) * i
    }
    val questionCorrectNums: IntArray = IntStream.range(0, 10000)
            .map { i -> Arrays.stream(outcomes).filter { outcome -> outcome.charAt(i) === '1' }.count() }
            .toArray()
    val sortedQuestions: IntArray = IntStream.range(0, 10000)
            .boxed()
            .sorted(Comparator.comparing { i -> questionCorrectNums[i] })
            .mapToInt { x -> x }
            .toArray()
    val q = DoubleArray(10000)
    for (i in q.indices) {
        q[sortedQuestions[i]] = 3 - 6.0 / (10000 - 1) * i
    }

    val diffs = IntArray(100)

    for (i in 1 until 100 - 1) {
        diffs[i] = realtime(
                q,
                outcomes[sortedPlayers[i]],
                s[sortedPlayers[i]],
                outcomes[sortedPlayers[i - 1]],
                s[sortedPlayers[i - 1]],
                outcomes[sortedPlayers[i + 1]],
                s[sortedPlayers[i + 1]])
    }

    println(Arrays.toString(Arrays.stream(diffs).sorted().toArray()))

    val sortedDiffs: IntArray = Arrays.stream(diffs).boxed().sorted(Comparator.reverseOrder()).mapToInt { x -> x }.toArray()
    if (sortedDiffs[0] - sortedDiffs[1] >= 50) {
        return (sortedPlayers[IntStream.range(1, 100 - 1)
                .boxed()
                .max(Comparator.comparing { i -> diffs[i] })
                .get()]
                + 1)
    }
    val maxPlayerCorrectNums: Int = Arrays.stream(playerCorrectNums).max().getAsInt()
    return (IntStream.range(0, outcomes.size)
            .filter { i -> playerCorrectNums[i] == maxPlayerCorrectNums }
            .findAny()
            .getAsInt()
            + 1)
}

fun realtime(
        q: DoubleArray,
        outcome: String?,
        s: Double,
        prevOutcome: String?,
        prevS: Double,
        nextOutcome: String?,
        nextS: Double): Int {
    return IntStream.range(0, 10000)
            .filter { i -> s - q[i] >= 1 && outcome!![i] == '0' && prevOutcome!![i] == '1' } 
            .count()
}