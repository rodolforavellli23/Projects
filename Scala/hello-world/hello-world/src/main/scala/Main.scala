object Main {
  
  def main(args: Array[String]): Unit = {

    def msg = "I was compiled by Scala 3\n"
    
    def hello() = {
    println("\nHello world!")
    println(msg)
    }

    hello()
  }
}

