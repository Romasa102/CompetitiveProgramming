import kotlin.math.pow

val visited: MutableSet<Double> = mutableSetOf()

fun recursion(xs:String): Boolean{
    var sum = 0.0
    for (x in xs) {
        sum += x.digitToInt().toDouble().pow(2)
    }
    if(sum == 1.0)return true
    if(visited.contains(sum))return false
    visited.add(sum)
    return recursion(sum.toInt().toString())
}
fun main(){
    var n = readln().toString()
    val ans = recursion(n)
    if(ans){
        println("Yes")
    }else{
        println("No")
    }
}