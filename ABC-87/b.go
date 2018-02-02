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

func cout(out string) { fmt.Println(out) }
func setScSplit()     { sc.Split(bufio.ScanWords) }
func stoi(str string) int {
  num, _ := strconv.Atoi(str)
  return num
}
func itos(num int) string {
  str := strconv.Itoa(num)
  return str
}
func gsf() string {
  sc.Scan()
  return sc.Text()
}
func gif() int {
  i := stoi(gsf())
  return i
}
func gff() float64 {
  f, _ := strconv.ParseFloat(gsf(), 64)
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
func push(t *[]int, x int) {
  tmp := *t
  *t = append(tmp, x)
}
func pop(t *[]int) int {
  tmp := *t
  x := tmp[len(tmp)-1]
  *t = tmp[:len(tmp)-1]
  return x
}
func deq(t *[]int) int {
  tmp := *t
  x := tmp[0]
  *t = tmp[1:]
  return x
}

//=============================================================

func main() {
  setScSplit()
  a, b, c := gif(), gif(), gif()
  x := gif()
  cnt := 0
  for i := 0; i <= a; i++ {
    for j := 0; j <= b; j++ {
      for k := 0; k <= c; k++ {
        if i*500+j*100+k*50 == x {
          cnt++
        }
      }
    }
  }
  cout(itos(cnt))
}
