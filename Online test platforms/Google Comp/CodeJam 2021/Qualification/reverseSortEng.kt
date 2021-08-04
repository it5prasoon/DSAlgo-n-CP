import java.lang.Integer.max

data class xCase(val listSize: Int, val costDesired: Int)

fun main() {
    val t = readLine()!!.toInt()

    for(i in 0 until t) {
        val x = readLine()!!.split(" ")
            .let { xCase(it[0].toInt(), it[1].toInt()) }
        val solution = solution(x)?.map { it.toString() }?.joinToString(" ")  ?: "IMPOSSIBLE"
        println("Case #${i + 1}: $solution")
    }
}

fun solution(x: xCase): List<Int?>? {

    val numberOfSteps = x.listSize - 1;
    if (x.costDesired < numberOfSteps) {
        return null
    } else if (((x.listSize) * (x.listSize + 1) / 2) - 1 < x.costDesired) {
        return null
    }

    val nbPerSteps = (0 until numberOfSteps).map { 1 }.toMutableList()
    var total = numberOfSteps
    for (i in 0 until numberOfSteps) {
        if (total + numberOfSteps - i + 1 > x.costDesired) {
            nbPerSteps[i] = max(1, x.costDesired - total + 1)
        } else {
            nbPerSteps[i] = numberOfSteps - i + 1
        }

        total = nbPerSteps.sum()
    }

    var requiredOutput = MutableList<Int?>(x.listSize) { null }
    requiredOutput[x.listSize - 1] = x.listSize

    nbPerSteps.reversed().forEachIndexed { index, nbItemsToReverse ->
        val nextItemIndex = requiredOutput.size - index - 2
        requiredOutput[nextItemIndex] = x.listSize - index - 1
        val reversedPart = requiredOutput.subList(nextItemIndex, nextItemIndex + nbItemsToReverse).reversed()
        requiredOutput = (requiredOutput.subList(0, nextItemIndex) + reversedPart + requiredOutput.subList(nextItemIndex + nbItemsToReverse, requiredOutput.size)).toMutableList()
    }

    return requiredOutput
}

