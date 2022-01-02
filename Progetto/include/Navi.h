#ifndef NAVI_H
#define NAVI_H
#include <vector>
using std::vector;

class Navi
{
public:
	Navi(bool, int, int, int);					//in costruttore prende in input se la nave è orizzontale, la posizione caratteristica della nave (vedere data members) e la lunghezza della nave
	void SetX(int);								//funzioni set e get per i data members
	void SetY(int);
	void SetHorizontal(bool);
	void SetLength(int);
	int GetX() const;
	int GetY() const;
	int GetLength() const;
	bool IsHorizontal() const;
	vector<bool> GetVector() const;
	
	//le funzioni draw stampano la casella che ricevono in ingresso; la funzione DrawEnemy stampa una X quando una casella è colpita e un punto altrimenti, mentre se
	// la nave è affondata stampa la lunghezza della nave in ogni casella; la funzione DrawAlly invece stampa la lunghezza della nave quando la cella non è colpita e
	//una X quando è colpita; in questo modo ci si assicura che il nemico veda solo le navi colpite o affondate, e che il giocatore di turno possa sempre vedere la
	//posizione delle sue navi.

	virtual void DrawEnemy(int, int) const;		
	virtual void DrawAlly(int, int) const;		 
	virtual bool Sunk() const;		//restituisce true se la nave è affondata, false altrimenti
	virtual void Strike(int, int);				//colpise la casella che riceve in input

private:
	int Length;					//indica la lunghezza della nave; se la nave ha lunghezza -1 allora è una nave acqua
	bool Horizontal;			//indica se la nave è orizzontale
	int X;						//X e Y indicano la posizione della cella più a sinistra se la nave è orizzontale; quella più in alto se la nave è verticale
	int Y;
	vector<bool> Hit;			//il vettore Hit rappresenta le caselle delle navi; se la n-esima casella è colpita, allora la n-esima cella di Hit è True, altrimenti è False
};

#endif

