import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*


var `in` = Scanner()
var output: PrintWriter = PrintWriter(System.out)
var testCases = 0
var a: String? = null
fun solve() {
    val ch = a!!.toCharArray()
    val n = ch.size
    if (ch[0] == '1') {
        val sb = StringBuilder()
        sb.append(ch[0]).append('0')
        for (i in 1 until n) {
            sb.append(ch[i])
        }
        output.println(sb.toString())
    } else {
        val sb = StringBuilder()
        sb.append('1')
        sb.append(a)
        output.println(sb.toString())
    }
    output.flush()
}

fun main(array: Array<String>) {
    testCases = `in`.nextInt()
    for (t in 0 until testCases) {
        a = `in`.next()
        solve()
    }
}

class Scanner {
    var `in`: BufferedReader = BufferedReader(InputStreamReader(System.`in`))
    var st: StringTokenizer? = null

    @Throws(IOException::class)
    operator fun next(): String {
        while (st == null || !st!!.hasMoreElements()) {
            st = StringTokenizer(`in`.readLine())
        }
        return st!!.nextToken()
    }

    @Throws(IOException::class)
    fun nextLine(): String {
        return `in`.readLine()
    }

    @Throws(IOException::class)
    fun nextInt(): Int {
        return next().toInt()
    }

    @Throws(IOException::class)
    fun nextLong(): Long {
        return next().toLong()
    }

}