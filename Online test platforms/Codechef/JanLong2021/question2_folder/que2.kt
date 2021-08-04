// Watching CPL

import java.util.*

// for (i in 4 downTo 1) print(i) // prints "4321"

fun main(args: Array<String>) {
        val scan = Scanner(System.`in`)
        var t = scan.nextInt()
        while (t-- != 0) {
            val n = scan.nextInt()
            val k = scan.nextInt()
            val h = IntArray(n)
            var hlinked = LinkedHashSet<Int?>()
            
            for (i in 0 until n) {
                h[i] = scan.nextInt()
            }
            Arrays.sort(h)
            hlinked.add(h[n - 1])
            var sum = h[n - 1]
            var z = -1
            for (i in n - 2 downTo 0) {
                val h2 = LinkedHashSet<Int?>()
                sum += h[i]
                // println(sum)
                val i1: Iterator<*> = hlinked.iterator()
                while (i1.hasNext()) {
                    val p = i1.next() as Int
                    // println(p)
                    h2.add(p)
                    h2.add(h[i])
                    h2.add(p + h[i])
                    // println(h2)
                    if (p + h[i] >= k && sum - p - h[i] >= k) {
                        z = n - i
                        break
                    }
                    if (h[i] >= k && sum - h[i] >= k) {
                        z = n - i
                        break
                    }
                }
                println(h2)
                if (z != -1) {
                    break
                }
                hlinked = h2
                println(hlinked)
            }
            println(z)
        }
}
