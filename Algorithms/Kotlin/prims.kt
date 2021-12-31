val INF = 99999
val V = 7

fun printGraph(parent: List<Int>, graph: List<List<Int>>){
    println("Edge \tWeight\n")
    for(i in 0..V){
        println("$parent[i] - $i \t$graph[i][parent[i]]")
    }
}

fun min_ele(distance: List<Int>, check: List<Int>): Int{
    var temp = INF
    var index = 0

    for(i in 0..V){
        if(check[i].equals(0) && distance[i] < temp){
            temp = distance[i]
            index = i
        }
    }
    return index
}

fun prims(graph: List<List<Int>>){
    var check = mutableListOf<Int>()
    var distance = mutableListOf<Int>()
    var parent = mutableListOf<Int>()

    for(i in 0..V){
        check.add(0)
        distance.add(INF)
        parent.add(0)
    }

    distance[0] = 0
    parent[0] = -1

    for(i in 0..V){
        var u = min_ele(distance, check)
        check[u] = 1

        for(j in 0..V){
            if(graph[u][j] == 0){
                continue
            }
            else
            {
                if(check[j] == 0){
                    if(graph[u][j] < distance[j]){
                        distance[j] = graph[u][j]
                        parent[j] = u
                    }
                }
            }
        }
    }

    printGraph(parent, graph)
}

fun main(){

    var graph = mutableListOf(
        mutableListOf(0, 28, 0, 0, 0, 10, 0),
        mutableListOf(28, 0, 16, 0, 0, 0, 14),
        mutableListOf(0, 16, 0, 12, 0, 0, 0),
        mutableListOf(0, 0, 12, 0, 22, 0, 18),
        mutableListOf(0, 0, 0, 22, 0, 25, 24),
        mutableListOf(10, 0, 0, 0, 25, 0, 0),
        mutableListOf(0, 14, 0, 18, 24, 0, 0)
    )

    prims(graph)

}