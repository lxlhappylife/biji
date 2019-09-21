/*
  给定一个字符串，找出其中不含重复字符的 最长子串，返回最长子串的长度。
  
  https://legacy.gitbook.com/book/siddontang/leetcode-solution/details
*/
/*
  思路：这个还是比较困难的，有几种不同的做法：
  1：蛮力法：判断每一个可能得子串是否包含重复字符。一次判断要字符串长度次数。
     算法实现大致是三层for循序实现。
  2：滑动窗口：一个可变的“窗口”，用来选定substring；
*/
