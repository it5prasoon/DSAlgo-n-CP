
fun main() {
    val t = readLine()!!.toInt()

    for(i in 0 until t) {
        readLine()
        val x = readLine()!!.split(" ").map(String::toInt)
        println("Case #${i + 1}: ${solution(x)}")
    }
}

fun solution(x: List<Int>): Int {

    var numList = x
    var cost = 0

    for(i in 0 until x.size - 1) {
        val min = numList.subList(i, numList.size).minOrNull()!!
        val minIndex = numList.indexOf(min) + 1

        val beforeReverse = numList.subList(0, i)
        val toReverse = numList.subList(i, minIndex)
        val afterReverse = numList.subList(minIndex, numList.size)

        numList = beforeReverse + toReverse.reversed() + afterReverse
        cost += toReverse.size
    }

    return cost
}