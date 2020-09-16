//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <cmath>
//#define rep(i,n) for(int i=0;i<n;i++)
//using namespace std;
//
//struct Point {
//	int x, y;
//	Point() {
//
//	}
//	Point(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//	bool operator < (const Point& v) const{
//		if (y == v.y)
//			return x < v.x;
//		else
//			return y < v.y;
//	}
//};
//
//bool cmp(const Point & a, const Point & b) {
//	return a.x < b.x;
//}
//
//int getDist(Point a, Point b) {
//	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
//}
//vector<Point> v;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int n;
//	cin >> n;
//	
//	rep(i, n) {
//		int a, b;
//		cin >> a >> b;
//		v.push_back(Point(a, b));
//	}
//	
//	// x에 대해서 정렬
//	sort(v.begin(), v.end(), cmp);
//
//	for (int k = 0; k < n; k += 2) {
//		//처음 두개 점으로 시작
//		
//		set<Point> candidate = { v[0],v[1] };
//		int ans = getDist(v[0], v[1]);
//		int start = 0;
//
//
//		Point p1 = v[0];
//		Point p2 = v[1];
//		for (int i = 2; i < n; i++) {
//			Point current = v[i];
//
//			while (start < i) {
//				auto p = v[start];
//				int x = current.x - p.x;
//				if (x * x > ans) {
//					candidate.erase(p);
//					start += 1;
//				}
//				else
//					break;
//			}
//
//			int d = (int)sqrt((double)ans) + 1;
//
//			auto lower_point = Point(-100000, current.y - d);
//			auto upper_point = Point(100000, current.y + d);
//			auto lower = candidate.lower_bound(lower_point);
//			auto upper = candidate.upper_bound(upper_point);
//			for (auto it = lower; it != upper; it++) {
//				int d = getDist(current, *it);
//				if (d < ans) {
//					p1 = current;
//					p2 = (*it);
//					ans = d;
//				}
//				else if (d == ans) {
//					if (current.y + (*it).y < p1.y + p2.y) {
//						p1 = current;
//						p2 = (*it);
//					}
//					else if (current.y + (*it).y == p1.y + p2.y) {
//						if (current.x + (*it).x < p1.x + p2.x) {
//							p1 = current;
//							p2 = (*it);
//						}
//					}
//				}
//
//			}
//			candidate.insert(current);
//		}
//		cout << ans << '\n';
//		cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << endl;
//		v.erase(remove(v.begin(), v.end(), p1), v.end());
//		v.erase(remove(v.begin(), v.end(), p2), v.end());
//	}
//}