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
fun nextString() = next().toString()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

var subStringSeq = ArrayList<String>()
val max = 1000000
var dp_a = IntArray(max+2)
var dp_b = IntArray(max+2)
var num_a = IntArray(max)
var num_b = IntArray(max)

fun findSubString(s: String, ans: String) {
    if (s.length == 0) {
        subStringSeq.add(ans)
        return
    }
    findSubString(s.substring(1), ans + s[0])
    findSubString(s.substring(1), ans)
}

@Throws(java.lang.Exception::class)
fun main(args: Array<String>) {
    var t = nextInt()
    while(t-- > 0) {
        solve()
    }
}


fun solve() {
    val s = nextString()
    
    var i: Int = 0
    val n = s.length
    var pos = -1

    for (i in 0 until n) {
        if(s[i] == '0') {
            for (j in (pos+1)..i) 
                num_a[j] = i
            pos = i
        }
    }
    
    for (i in (pos+1) until n) {
        num_a[i] = n;
    }

    if(num_a[0]==n) {
        println("0")
        return
    }

    pos = -1;

    for (i in 0 until n) {
        if(s[i] == '1') {
            for (j in (pos+1)..i) 
                num_b[j] = i
            pos = i
        }
    }
    
    for (i in (pos+1) until n) {
        num_b[i] = n;
        println(num_b[i])
    }

    dp_a[n] = 0
    dp_a[n+1] = 0
    dp_b[n] = 0
    dp_b[n+1] = 0
    dp_a[n] = dp_a[n+1]
    dp_b[n] = dp_b[n+1]

    for (i in (n-1).downTo(0)) {
        dp_a[i] = dp_a[i+1]
        if(s[i]=='0' && num_b[i]<n) dp_a[i]=max(dp_a[i],dp_a[num_b[i]+1]+1)
        if(s[i]=='1' && num_a[i]<n) dp_a[i]=max(dp_a[i],dp_a[num_a[i]+1]+1)
        dp_b[i] = dp_b[i+1]
        if(num_b[i]<n) dp_b[i]=max(dp_b[i],dp_a[num_b[i]+1]+1)
    }

    

    var len = dp_b[0] + 1
    var current = num_b[0]+1
    var ans = "1"

    // println(current)
    for (i in 1 until len) {
        if(current >= n) {
            ans+="0"
            continue
        }

        if(num_a[current] >= n) {
            ans+="0"
            current = num_a[current]+1
            continue
        }

        if (dp_a[num_a[current]+1]<len-i-1) {
            ans+="0"
            current = num_a[current] +1
        } else {
            ans+="1"
            current = num_b[current] + 1
        }

    }

    println(ans)
}

fun max(x: Int, y:Int): Int {
    if(x>y){
        return x;
    }
    return y;
}


