/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   합분해.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 05:16:21 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 14:44:03 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

/*

   어케 풀지?

   예제 입력
   20 2

   0부터 N까지 K개를 더해서 N이 되는 경우
   0부터 20까지 2개를 더해서 20이 되는 경우
   -> 20 = 1 + 19 = 2 + 18 = ... = 10 + 10 = ... = 19 + 1
   
   K = 3 이라면?
   20 = 1 + (19를 2개로 선택하는 개수)
   ...

*/

int main(void)
{
	int N;
	int K;
	int **d;
	const int b = 1000000000;

	cin >> N;
	cin >> K;

	d = new int*[N + 1];
	for(int i = 0; i <= N; i++)
		d[i] = new int[200 + 1];

	//i를 1개로 만드는 경우의 수
	for(int n = 0; n <= N; n++)
		d[n][1] = 1;

	for(int n = 0; n <= N; n++) {
		for(int k = 1; k <= 200; k++) {
			for(int i = 0; i <= n; i++) {
				d[n][k] += (d[n - i][k - 1] % b);
				d[n][k] = d[n][k] % b;
			}
		}
	}

	cout << d[N][K] << endl;
	for(int i = 0; i <= N; i++)
		delete d[i];
	delete[] d;
}
