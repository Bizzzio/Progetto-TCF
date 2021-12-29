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
	void SetLength(int);
	int GetX() const;
	int GetY() const;
	int GetLength() const;
	bool IsHorizontal() const;
	virtual void DrawEnemy(int, int) const = 0;
	virtual void DrawAlly(int, int) const = 0;
	virtual bool Sunk(vector<bool>) const = 0;
	virtual void Strike(int, int)=0;

private:
	int length;
	bool Horizontal;
	int X;
	int Y;
};

#endif
