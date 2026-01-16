fun f(x: Int): Int {
    var cur = x + 1
    return cur
}

fun main() {
    var n = readln().toInt() // read integer from the input
    println(f(n)) // print answer to the output
}