data class xCase(val costCJ : Int, val costJC : Int, val mString: String)

fun main() {
    val nbOfCase = readLine()!!.toInt()

    for(i in 0 until nbOfCase) {
        val x = readLine()!!.split(" ")
            .let { xCase(it[0].toInt(), it[1].toInt(), it[2]) }
        println("Case #${i + 1}: ${solution(x)}")
    }
}


fun solution(x: xCase) : Int {
    val mWInterr = if (x.costCJ + x.costJC < 0) {
        negativeInputTransformation(x)
    } else {
        x.mString.replace(Regex("\\?"), "")
    }

    var price = 0
    for(i in 0 until mWInterr.length - 1) {
        val currentChar = mWInterr[i]
        val nextChar = mWInterr[i + 1]
        price += when {
            currentChar == 'C' && nextChar == 'J' -> x.costCJ
            currentChar == 'J' && nextChar == 'C' -> x.costJC
            else -> 0
        }
    }

    return price
}

private fun negativeInputTransformation(x: xCase): String {
    val pairsAtLowCost = if (x.costJC < 0) {
        "JC"
    } else {
        "CJ"
    }

    var i = 0
    var tMural = x.mString
    while(i < tMural.length) {
        if(tMural[i] != '?') {
            i++
        } else {
            val start = i
            while (i < tMural.length && tMural[i] == '?') {
                i++
            }

            var iMaGroup = tMural.substring(start, i)
            val cBefore = tMural.getOrNull(start - 1)
            val cAfter = tMural.getOrNull(i)
            val interrogationRegex = Regex("\\?{2}")
            iMaGroup = if (iMaGroup.length % 2 == 0) {
                iMaGroup.replace(interrogationRegex, pairsAtLowCost)
            } else {
                if(cBefore == pairsAtLowCost[0]) {
                    pairsAtLowCost[1] + iMaGroup.drop(1).replace(interrogationRegex, pairsAtLowCost)
                } else if(cAfter == pairsAtLowCost[1]) {
                    iMaGroup.dropLast(1).replace(interrogationRegex, pairsAtLowCost) + pairsAtLowCost[0]
                } else {
                    iMaGroup.replace(interrogationRegex, pairsAtLowCost)
                }
            }

            tMural = tMural.substring(0, start) + iMaGroup + tMural.substring(i)

        }
    }

    return tMural.replace(Regex("\\?"), "")
}

