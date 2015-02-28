/**
 * Author: Per Austrin
 * Date: 2009-04-17
 * Source: tinyKACTL
 * Description: Solves $A * x = b$, or as much of $x$ as possible. Returns rank.
 * Data in $A$ and $b$ is lost.
 * Time: O(n^3)
 * Usage: double A[3][3], b[3], x[3];
 int rank = solve_linear(3,A,b,x);
 * Status: Unknown
 */
#pragma once

#include <cmath>
#include <algorithm>
using namespace std;

const double undefined = 1.0/0.0;
const double eps = 1e-12;

template <int N> int
solve_linear(int n, double A[N][N], double b[N], double x[N]) {
	int row[N], col[N], undef[N], invrow[N], invcol[N], rank = 0;
	rep(i,0,n) row[i] = col[i] = i, undef[i] = false;
#define A(i,j) A[row[i]][col[j]]
#define B(i) b[row[i]]

	for (int i = 0; i < n; rank = ++i) {
		int br = i, bc = i;
		double v, bv = -1;
		rep(r,i,n) rep(c,i,n)
			if ((v = fabs(A(r,c))) > bv)
				br = r, bc = c, bv = v;
		if (bv < eps) break;
		bv = A(br,bc);
		swap(row[i], row[br]);
		swap(col[i], col[bc]);
		rep(j,i+1,n) {
			double fac = A(j,i) / bv;
			A(j,i) = 0;
			B(j) -= fac * B(i);
			rep(k,i+1,n) A(j,k) -= fac*A(i,k);
		}
	}

	for (int i = rank; i--; ) {
		B(i) /= A(i,i);
		A(i,i) = 1;
		rep(j,rank,n) if(fabs(A(i,j)) > eps)
			undef[i] = true;
		for (int j = i - 1; j >= 0; --j) {
			if (undef[i] && fabs(A(j,i)) > eps)
				undef[j] = true;
			else {
				B(j) -= A(j,i) * B(i);
				A(j,i) = 0;
			}
		}
	}

	rep(i,0,n) invrow[row[i]] = i, invcol[col[i]] = i;
	rep(i,0,n) if(invrow[i] >= rank || undef[invrow[i]])
		b[i] = undefined;
	rep(i,0,n) x[i] = B(invcol[i]);
	return rank;
}
