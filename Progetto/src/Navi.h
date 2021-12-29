#ifndef NAVI_H
#define NAVI_H
#include <vector>
using std::vector;

class Navi
{
public:
	void SetX(int);
	void SetY(int);
	void SetHorizontal(bool);
	int GetX() const;
	int GetY() const;
	bool IsHorizontal() const;
	vector<bool> GetVector() const;
	virtual void DrawEnemy(int, int) const = 0;
	virtual void DrawAlly(int, int) const = 0;
	virtual bool Sunk(vector<bool>) const = 0;

private:
	//int length;
	bool Horizontal;
	vector<bool> Hit;
	int X;
	int Y;
};

#endif
