package main

import "bufio"
import "fmt"
import "os"
import "sort"
import "strconv"

//============================================================
var sc = bufio.NewScanner(os.Stdin)

func setScSplit() { sc.Split(bufio.ScanWords) }
func readStr() string {
  sc.Scan()
  return sc.Text()
}
func readInt() int {
  i, _ := strconv.Atoi(readStr())
  return i
}
func readFloat() float64 {
  f, _ := strconv.ParseFloat(readStr(), 64)
  return f
}

func uniq(list []int) []int {
  m := make(map[int]struct{}) // 空のstructを使う
  for _, ele := range list {
    m[ele] = struct{}{} // m["a"] = struct{}{} が二度目は同じものとみなされて重複が消える。
  }
  uni := []int{}
  for i := range m {
    uni = append(uni, i)
  }
  return uni
}

func usort(list []int) []int {
  sort.Sort(sort.IntSlice(list))
  return list
}
func dsort(list []int) []int {
  sort.Sort(sort.Reverse(sort.IntSlice(list)))
  return list
}

//=============================================================

func main() {
  setScSplit()
  n := readInt()
  list := []int{}
  for i := 0; i < n; i++ {
    list = append(list, readInt())
  }
  dsort(list)
  list = uniq(list)
  fmt.Println(len(list))

}
