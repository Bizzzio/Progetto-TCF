#ifndef NAVI_H
#define NAVI_H
#include <vector>
using std::vector;

class Navi()
{
public:
	void SetX(int);
	void SetY(int);
	void SetHorizontal(bool);
	int GetX() const;
	int GetY() const;
	bool IsHorizontal() const;
	vector<bool> GetVector() const;

private:
	bool Horizontal;
	vector<bool> Hit;
	int X;
	int Y;
	virtual bool Ok() const = 0;
};

#endif
