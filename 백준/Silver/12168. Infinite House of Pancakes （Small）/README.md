# [Silver I] Infinite House of Pancakes (Small) - 12168 

[문제 링크](https://www.acmicpc.net/problem/12168) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2026년 4월 8일 22:51:38

### 문제 설명

<p>At the Infinite House of Pancakes, there are only finitely many pancakes, but there are infinitely many diners who would be willing to eat them! When the restaurant opens for breakfast, among the infinitely many diners, exactly  <strong>D</strong> have non-empty plates; the <strong>i</strong>th of these has <strong>P<sub>i</sub></strong> pancakes on his or her plate. Everyone else has an empty plate.<br>
<br>
Normally, every minute, every diner with a non-empty plate will eat one pancake from his or her plate. However, some minutes may be <em>special</em>. In a special minute, the head server asks for the diners' attention, chooses a diner with a non-empty plate, and carefully lifts some number of pancakes off of that diner's plate and moves those pancakes onto one other diner's (empty or non-empty) plate. No diners eat during a special minute, because it would be rude.<br>
<br>
You are the head server on duty this morning, and it is your job to decide which minutes, if any, will be special, and which pancakes will move where. That is, every minute, you can decide to either do nothing and let the diners eat, or declare a special minute and interrupt the diners to make a single movement of one or more pancakes, as described above.<br>
<br>
Breakfast ends when there are no more pancakes left to eat. How quickly can you make that happen?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> test cases follow. Each consists of one line with <strong>D</strong>, the number of diners with non-empty plates, followed by another line with <strong>D</strong> space-separated integers representing the numbers of pancakes on those diners' plates.</p>

<h3>Limits</h3>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 100.</li>
	<li>1 ≤ <strong>D</strong> ≤ 6.</li>
	<li>1 ≤ <strong>P<sub>i</sub></strong> ≤ 9.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the smallest number of minutes needed to finish the breakfast.</p>

