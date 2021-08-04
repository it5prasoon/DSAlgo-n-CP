import java.util.*


fun main(args: Array<String>) {
    try {
        val sc = Scanner(System.`in`)
        var t = sc.nextInt()
        while (t-- > 0) {
            val n = sc.nextInt()
            val m = sc.nextInt()
            val k = sc.nextInt()

            val arr = Array(n) { LongArray(m) }

            var count = 0
            
            for (i in 0 until n) {
                for (j in 0 until m) {
                    arr[i][j] = sc.nextInt().toLong()
                    if (arr[i][j] >= k) {
                        count++
                    }
                }
            }
            val dp = Array(n) { LongArray(m) }
            
            for (i in 0 until n) {
                for (j in 0 until m) {
                    dp[i][j] = 0
                }
            }
            
            dp[0][0] = arr[0][0]
            for (j in 0 until m) {
                dp[0][j] = arr[0][j] + (if(j-1<0) 0 else dp[0][j-1])
            }

            for (i in 0 until n) {
                dp[i][0] = arr[i][0] + (if(i-1<0) 0 else dp[i-1][0])
            }

            for (i in 1 until n) {
                for (j in 1 until m) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] -
                                dp[i-1][j-1] + arr[i][j]
                    // print(dp[i][j])
                }
            }

            
            var r_prev = 0
            for (l in 2 until minimum(n,m)+1) {
                val dpa = dp[l-1][l-1]

                if (dpa >= k*l*l) {
                    count += (m-(l-1))*(n-(l-1))
                    continue
                }

                var r_start = 0
                if (r_prev == 0) {
                    r_prev = l-1
                }

                for (i in r_prev until n) {
                    var pre: Long = 0
                    for (j in (n-l) until n) {
                        pre+=arr[i][j]
                    } 
                    if (pre >= l*k) {
                        r_start = i
                        break
                    }
                }

                if (r_start == 0)
                    continue
                r_prev = maximum(r_start, l)

                var dpa_prev = 0
                var worthy_bool = false

                for (i in r_start until n) {
                    var c_start = 0
                    var left = l-1
                    var right = m-1

                    while (left <= right) {
                        val mid: Int = (left+right)/2
                        
                        val sub_sum: Long = dp[i][mid] - 
                        (if(i-l<0) 0 else dp[i-l][mid]) -
                        (if(mid-l<0) 0 else dp[i][mid-l]) +
                        (if(mid-l<0 || i-l<0) 0 else dp[i-l][mid-l])
                        
                        // print(sub_sum)
                        if (sub_sum < k*l*l) {
                            left = mid + 1
                        } else if (sub_sum >= k*l*l) {
                            right = mid -1
                            c_start = mid
                        } 
                    }

                    if (c_start != 0){
                        if (c_start == l-1) {
                            count += (m - c_start) * (n - i)
                            break
                        }
                        else{
                            count += (m - c_start)
                            continue
                        }
                    }
                }
            }
            
            println(count)
            
        }
    } catch (e: Exception) {
        return
    }
}

fun maximum(x: Int, y: Int): Int {
    if (x>y) return x 
    else return y
}

fun minimum(x: Int, y: Int): Int {
    if (x<y) return x 
    else return y
}
