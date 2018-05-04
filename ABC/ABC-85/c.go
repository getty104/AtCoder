package main

import (
  "bufio"
  "fmt"
  "os"
  "sort"
  "strconv"
)

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
  n, y := readInt(), readInt()
  a1, a2, a3 := -1, -1, -1
  for i := 0; i <= n; i++ {
    for j := 0; j <= n; j++ {
      k := n - i - j
      if k < 0 {
        continue
      }
      if i*10000+j*5000+k*1000 == y {
        a1, a2, a3 = i, j, k
      }
    }
  }
  fmt.Println(strconv.Itoa(a1) + " " + strconv.Itoa(a2) + " " + strconv.Itoa(a3))
}
