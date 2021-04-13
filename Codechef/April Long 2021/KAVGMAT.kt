import java.util.*


fun main(args: Array<String>) {
    try {
        val sc = Scanner(System.`in`)
        var t = sc.nextInt()
        while (t-- > 0) {
            val n = sc.nextInt()
            val m = sc.nextInt()
            val k = sc.nextInt()

            val arr = Array(n + 1) { LongArray(m + 1) }

            var count = 0
            
            for (i in 0 until n + 1) {
                for (j in 0 until m + 1) {
                    if (i == 0 || j == 0) {
                        arr[i][j] = 0
                    } else {
                        arr[i][j] = sc.nextInt().toLong()
                    }
                    if (arr[i][j] >= k) {
                        count++
                    }
                }
            }
            // for (i in 1 until n + 1) {
            //     for (j in 1 until m + 1) {
            //         print(arr[i][j])
            //     }
            //     println()
            // }
            println(count+solve(arr, n, m, k))
        }
    } catch (e: Exception) {
        return
    }
}

fun solve(arr: Array<LongArray>, n: Int, m: Int, k: Int): Long {
    var ans: Long = 0

    for(i in 0..n)
    {
        var pre: Long = 0
        for(j in 0..m)
        {
            arr[i][j]+=pre
            pre=arr[i][j]
        }
    }

    for(j in 0..m)
    {
        var pre: Long = 0
        for(i in 0..n)
        {
            arr[i][j]+=pre
            pre=arr[i][j]
        }
    }

    var minimum: Int = 0
    if (m>n) {
        minimum = n
    } else {
        minimum = m
    }

    for(l in 2..minimum)
    {
        for(i in l..n)
        {
            for(j in l..m)
            {
                var sum: Long = arr[i][j] + arr[i-l][j-l] -
                             arr[i-l][j] - arr[i][j-l]
                sum = sum/(l*l)
                if( sum >= k)
                {
                    ans++
                }
            }
        }
    }

    return ans
}

