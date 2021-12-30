#ifndef NAVI_H
#define NAVI_H
#include <vector>
using std::vector;

class Navi
{
public:
	Navi(bool, int, int, int);
	void SetX(int);
	void SetY(int);
	void SetHorizontal(bool);
	void SetLength(int);
	int GetX() const;
	int GetY() const;
	int GetLength() const;
	bool IsHorizontal() const;
	vector<bool> GetVector() const;
	virtual void DrawEnemy(int, int) const;
	virtual void DrawAlly(int, int) const;
	virtual bool Sunk(vector<bool>) const;
	virtual void Strike(int, int);

private:
	int Length;
	bool Horizontal;
	int X;
	int Y;
	vector<bool> Hit;
};

#endif

