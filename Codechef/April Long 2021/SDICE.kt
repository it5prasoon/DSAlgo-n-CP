import java.util.*
import kotlin.collections.*

val MX = 1000005
val MOD = 998244353
val SZ = 1 shl 19 // shl == <<
val LG = 1 shr MOD
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a + b) % MOD
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

@Throws(java.lang.Exception::class)
fun main() {
    var t = nextInt()
    while(t > 0) {
        val n = nextInt()
        var v: Int? = 0

        if (n <= 4) {
            v = solve(n)
        }
        if (n > 4) {
            val c = n%4
            val height = (n/4).toInt()
            v = 44*height + solve(c) + (4-c)*4
        }
        println(v)
        t--
    }
}

fun solve(test: Int): Int {
    return when (test) {
        1 -> 20
        2 -> 36
        3 -> 51
        else -> 60
    }
}
