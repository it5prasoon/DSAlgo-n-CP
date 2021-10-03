import java.util.*

internal object Codechef {
    @Throws(Exception::class)
    @JvmStatic
    fun main(args: Array<String>) {
        val scan = Scanner(System.`in`)
        var t = scan.nextInt()
        while (t-- != 0) {
            val n = scan.nextInt()
            val k = scan.nextInt()
            val h = IntArray(n)
            var h1 = LinkedHashSet<Int?>()
            
            for (i in 0 until n) {
                h[i] = scan.nextInt()
            }
            Arrays.sort(h)
            h1.add(h[n - 1])
            var sum = h[n - 1]
            var z = -1
            for (i in n - 2 downTo 0) {
                val h2 = LinkedHashSet<Int?>()
                sum += h[i]
                val i1: Iterator<*> = h1.iterator()
                while (i1.hasNext()) {
                    val p = i1.next() as Int
                    h2.add(p)
                    h2.add(h[i])
                    h2.add(p + h[i])
                    if (p + h[i] >= k && sum - p - h[i] >= k) {
                        z = n - i
                        break
                    }
                    if (h[i] >= k && sum - h[i] >= k) {
                        z = n - i
                        break
                    }
                }
                if (z != -1) {
                    break
                }
                h1 = h2
            }
            println(z)
        }
    }
}