fun main(arg: Array<String>){
    var u: Long
    var ans: Long
    var (n, p, m) = readLine()!!.split(" ").map(String::toInt)
    u = 0
    var k = 1
    ans = 0
    for (i in 1..n) {
        var (d, t) = readLine()!!.split(" ").map(String::toInt)
        u = u - (d - k) * p
        if (u < 0) if ((-u + p - 1) / p < d - k) ans += (-u + p - 1) / p else ans += d - k
        u = u + t
        k = d
    }
    u = u - (m - k + 1) * p
    if (u < 0) if ((-u + p - 1) / p < m - k + 1) ans += (-u + p - 1) / p else ans += m - k + 1
    println(ans)
}

