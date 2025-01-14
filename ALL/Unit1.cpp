//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1* Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {}
//---------------------------------------------------------------------------
byte SumPar(Cardinal n)
{
    byte cont;
    if (n == 0) {
        cont = 0;
    } else {
        byte d = n % 10;
        n /= 10;
        cont = SumPar(n);
        if ((d % 2) == 0)
            cont++;
    }
    return cont;
}
void __fastcall TForm1::SUMADEPARES1Click(TObject* Sender)
{
    Edit2->Text = SumPar(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void MovFinal(Cardinal &n)
{
    if (n > 9) {
        byte d = n % 10;
        n /= 10;
        MovFinal(n);
        if ((n % 10) > d) {
            d = d * 10 + (n % 10);
            n /= 10;
            n = n * 100 + d;
        } else {
            n = n * 10 + d;
        }
    }
}
void __fastcall TForm1::MOVMAYORFINAL1Click(TObject* Sender)
{
    Cardinal n = StrToInt(Edit1->Text);
    MovFinal(n);
    Edit2->Text = n;
}
//---------------------------------------------------------------------------
bool Ordenado(Cardinal n)
{
    bool b;
    if (n < 10) {
        b = true;
    } else {
        byte d = n % 10;
        n /= 10;
        b = Ordenado(n);
        if ((n & 10) > d)
            b = false;
    }
    return b;
}
void __fastcall TForm1::VERFICARORDENADO1Click(TObject* Sender)
{
    Edit2->Text = BoolToStr(Ordenado(StrToInt(Edit1->Text)), true);
}
//---------------------------------------------------------------------------
byte ParImpar(Cardinal n)
{
    byte cont;
    if (n < 10) {
        cont = 0;
    } else {
        byte d = n % 100;
        n /= 10;
        cont = ParImpar(n);
        if ((n / 10) % 2 == 0 && (n % 10) % 2 != 0)
            cont++;
    }
}
void __fastcall TForm1::PARANTESDEUNIMPAR1Click(TObject* Sender)
{
    Edit2->Text = ParImpar(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void CargarRandom(TStringGrid* v, byte n)
{
    if (n > 0) {
        v->Cells[n - 1][0] = Random(20) + 1;
        CargarRandom(v, n - 1);
    }
}
void __fastcall TForm1::CARGARRANDOM1Click(TObject* Sender)
{
    StringGrid1->ColCount = StrToInt(Edit1->Text);
    CargarRandom(StringGrid1, StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject* Sender)
{
    StringGrid1->ColCount = StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------
byte ContPar(TStringGrid* v, byte n)
{
    byte cont;
    if (n == 0) {
        cont = 0;
    } else {
        Cardinal d = StrToInt(v->Cells[n - 1][0]);
        cont = ContPar(v, n - 1);
        if (d % 2 == 0)
            cont++;
    }
    return cont;
}
void __fastcall TForm1::CONTARPARES1Click(TObject* Sender)
{
    StringGrid1->ColCount = StrToInt(Edit1->Text);
    Edit2->Text = ContPar(StringGrid1, StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void ElimCel(TStringGrid* v, byte n, byte b)
{
    if (n == b) {
        v->ColCount--;
    } else {
        v->Cells[b][0] = v->Cells[b + 1][0];
        ElimCel(v, n, b + 1);
    }
}
void EliminarDato(TStringGrid* v, byte n, Cardinal dato)
{
    if (n > 0) {
        Cardinal num = StrToInt(v->Cells[n - 1][0]);
        if (num == dato) {
            ElimCel(v, v->ColCount, n - 1);
        }
        EliminarDato(v, n - 1, dato);
    }
}
void __fastcall TForm1::ELIMINARDIG1Click(TObject* Sender)
{
    StringGrid1->ColCount = StrToInt((Edit1->Text));
    EliminarDato(StringGrid1, StringGrid1->ColCount, StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------
void Invertir(TStringGrid* v, byte a, byte b)
{
    if (a < b) {
        Cardinal aux = StrToInt(v->Cells[a - 1][0]);
        v->Cells[a - 1][0] = v->Cells[b - 1][0];
        v->Cells[b - 1][0] = StrToInt(aux);
        Invertir(v, a + 1, b - 1);
    }
}
void __fastcall TForm1::INVERTIRENTREAYB1Click(TObject* Sender)
{
    Invertir(StringGrid1, StrToInt(Edit1->Text), StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------
bool Palindrome(TStringGrid* v, byte n)
{
    bool bo = true;
    if (n > 1) {
        byte col = v->ColCount - n;
        Cardinal a = StrToInt(v->Cells[col][0]);
        Cardinal b = StrToInt(v->Cells[n - 1][0]);
        bo = Palindrome(v, n - 1);
        if ((a != b))
            bo = false;
    }
    return bo;
}
void __fastcall TForm1::VERFPALINDROME1Click(TObject* Sender)
{
    StringGrid1->ColCount = StrToInt(Edit1->Text);
    Edit2->Text =
        BoolToStr(Palindrome(StringGrid1, StringGrid1->ColCount), true);
}
//---------------------------------------------------------------------------
Cardinal Fac(Cardinal n)
{
    Cardinal fac;
    if (n == 0)
        fac = 1;
    else
        fac = Fac(n - 1) * n;
    return fac;
}
void VecFac(TStringGrid* v, byte n)
{
    if (n > 0) {
        Cardinal d = StrToInt(v->Cells[n - 1][0]);
        VecFac(v, n - 1);
        v->Cells[n - 1][0] = StrToInt(Fac(d));
    }
}

void __fastcall TForm1::FACTORIALNUM1Click(TObject* Sender)
{
    StringGrid1->ColCount = StrToInt(Edit1->Text);
    VecFac(StringGrid1, StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
bool NumPri(Cardinal n, Cardinal nn)
{
    bool bo;
    if (n == 1 || n == 0) {
        bo = false;
    } else {
        if (n == 2) {
            bo = true;
        } else {
            Cardinal n1 = n - 1;
            bo = NumPri(n - 1, nn);
            if (nn % n1 == 0)
                bo = false;
        }
    }
    return bo;
}
byte VecPri(TStringGrid* v, byte n)
{
    byte cont;
    if (n == 0) {
        cont = 0;
    } else {
        Cardinal d = StrToInt(v->Cells[n - 1][0]);
        cont = VecPri(v, n - 1);
        if (NumPri(d, d))
            cont++;
    }
    return cont;
}
void __fastcall TForm1::NUMPRIM1Click(TObject* Sender)
{
    StringGrid1->ColCount = StrToInt(Edit1->Text);
    Edit2->Text = VecPri(StringGrid1, StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void Invertir(TStringGrid* v, byte n)
{
    if (n > 1) {
        Cardinal a = StrToInt(v->ColCount - n);
        Cardinal b = StrToInt(n - 1);
        Invertir(v, n - 1);
        if (a < b) {
            AnsiString aux = v->Cells[a][0];
            v->Cells[a][0] = v->Cells[b][0];
            v->Cells[b][0] = aux;
        }
    }
}
void __fastcall TForm1::INVERTIR1Click(TObject* Sender)
{
    StringGrid1->ColCount = StrToInt(Edit1->Text);
    Invertir(StringGrid1, StringGrid1->ColCount);
}
//---------------------------------------------------------------------------
void Recorrer(TStringGrid* v, byte pos, byte n)
{
    if (pos == n) {
        v->ColCount--;
    } else {
        AnsiString q = v->Cells[pos - 1][0];
        v->Cells[pos - 1][0] = v->Cells[pos][0];
        v->Cells[pos][0] = q;
        Recorrer(v, pos + 1, n);
    }
}
void EliminarMPos(TStringGrid* v, byte n, byte m, byte pos)
{
    if (pos > n || pos == 1 || m > n) {
        throw Exception("Error de Dato");
    }
    if (m > 0) {
        Recorrer(v, pos, n);
        EliminarMPos(v, n, m - 1, pos);
    }
}
void __fastcall TForm1::ELIMINARMDESEP1Click(TObject* Sender)
{
    byte pos = StrToInt(Edit3->Text);
    StringGrid1->ColCount = StrToInt(Edit1->Text);
    EliminarMPos(
        StringGrid1, StringGrid1->ColCount, StrToInt(Edit2->Text), pos + 1);
}
//---------------------------------------------------------------------------
AnsiString Vocal(AnsiString cad)
{
    AnsiString vocales;
    AnsiString abc = "aeiouAEIUO";
    if (cad.Length() == 0) {
        vocales = "";
    } else {
        char voc = cad[1];
        cad.Delete(1, 1);
        vocales = Vocal(cad);
        if (abc.Pos(voc) > 0)
            vocales = AnsiString(voc) + vocales;
        return vocales;
    }
}
void CargarVocal(TStringGrid* v, AnsiString cad)
{
    if (cad.Length() > 0) {
        byte p = cad.LastDelimiter(" ");
        AnsiString pal = cad.SubString(p + 1, cad.Length() - p);
        cad.SetLength(p - 1);
        CargarVocal(v, cad);
        pal = Vocal(pal);
        if (pal != "") {
            if (v->Cells[v->ColCount - 1][0] != "")
                v->ColCount++;
            v->Cells[v->ColCount - 1][0] = pal;
        }
    }
}
void __fastcall TForm1::CARGARVOCALCAD1Click(TObject* Sender)
{
    StringGrid1->ColCount = 0;
    CargarVocal(StringGrid1, Edit1->Text);
}
//---------------------------------------------------------------------------
void MoverMenor(Cardinal &n)
{
    if (n > 9) {
        byte d = n % 10;
        n /= 10;
        MoverMenor(n);
        if ((n % 10) < d) {
            d = d * 10 + (n % 10);
            n /= 10;
            n = n * 100 + d;
        } else {
            n = n * 10 + d;
        }
    }
}
void CargarOrdenado(TStringGrid* v, Cardinal n)
{
    if (n < 10) {
        v->Cells[v->ColCount - 1][0] = n;
    } else {
        MoverMenor(n);
        byte d = n % 10;
        n /= 10;
        v->Cells[v->ColCount - 1][0] = d;
        v->ColCount++;
        CargarOrdenado(v, n);
    }
}
void __fastcall TForm1::CARGARNUMORDEANDO1Click(TObject* Sender)
{
    StringGrid1->ColCount = 0;
    CargarOrdenado(StringGrid1, StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void CargarElemPal(TStringGrid* v, AnsiString cad)
{
    if (cad == "")
        throw Exception("PONGA ALMENOS UNA CARACTER");
    AnsiString abc = "qwertyuiopasdfghjkl�zxcvbnmQWERTYUIOPASDFGHJKL�ZXCVBNM";
    if (cad.Length() == 1) {
        if (abc.Pos(cad) > 0)
            v->Cells[v->ColCount - 1][0] = cad;
    } else {
        char pal = cad[cad.Length()];
        cad.Delete(cad.Length(), 1);
        if (abc.Pos(pal) > 0) {
            v->Cells[v->ColCount - 1][0] = pal;
            v->ColCount++;
        }
        CargarElemPal(v, cad);
    }
}
void __fastcall TForm1::CARGARCONELEMDELABECE1Click(TObject* Sender)
{
    StringGrid1->ColCount = 0;
    CargarElemPal(StringGrid1, Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject* Sender)
{
    StringGrid3->RowCount = StrToInt(Edit1->Text);
    StringGrid3->ColCount = StrToInt(Edit2->Text);
}
//---------------------------------------------------------------------------
void Rellenar1(TStringGrid* v, byte m, byte n, byte &k)
{
    if (n > 0) {
        v->Cells[n - 1][m - 1] = k++;
        Rellenar1(v, m, n - 1, k);
    }
}
void Cargar1(TStringGrid* v, byte m, byte n, byte &k)
{
    if (m > 0) {
        Rellenar1(v, m, m, k);
        Cargar1(v, m - 1, n, k);
    }
}
void __fastcall TForm1::CARGAR1Click(TObject* Sender)
{
    byte k = 1;
    Cargar1(StringGrid3, StringGrid3->RowCount, StringGrid3->ColCount, k);
}
//---------------------------------------------------------------------------
void Rellenar2(TStringGrid* v, byte fa, byte m, byte ca, byte &k)
{
    if (m > 0) {
        v->Cells[ca - 1][fa - 1] = k++;
        Rellenar2(v, fa + 1, m - 1, ca, k);
    }
}
void Cargar2(TStringGrid* v, byte m, byte n, byte &k)
{
    if (n > 0) {
        Cargar2(v, m, n - 1, k);
        Rellenar2(v, n, (m - n) + 1, n, k);
    }
}
void __fastcall TForm1::CARGAR21Click(TObject* Sender)
{
    byte k = 1;
    Cargar2(StringGrid3, StringGrid3->RowCount, StringGrid3->ColCount, k);
}
//---------------------------------------------------------------------------
void Rellenar3(TStringGrid* v, byte m, byte n, byte fa, byte &k)
{
    if (m > 0) {
        if ((n % 2 != 0)) {
            v->Cells[n - 1][fa] = k++;
            Rellenar3(v, m - 1, n, fa + 1, k);
        } else {
            v->Cells[n - 1][m - 1] = k++;
            Rellenar3(v, m - 1, n, fa, k);
        }
    }
}
void Cargar3(TStringGrid* v, byte n, byte fa, byte &k)
{
    if (n > 0) {
        Cargar3(v, n - 1, fa, k);
        Rellenar3(v, v->RowCount, n, fa, k);
    }
}
void __fastcall TForm1::CARGAR31Click(TObject* Sender)
{
    byte k = 1;
    Cargar3(StringGrid3, StringGrid3->ColCount, 0, k);
}
//---------------------------------------------------------------------------
void Rellenar4(TStringGrid* v, byte mn, byte fb, byte ca, byte &k)
{
    if (ca <= mn || fb > 0) {
        if (ca <= mn) {
            v->Cells[ca - 1][mn - 1] = k;
            Rellenar4(v, mn, fb, ca + 1, k);
        } else {
            v->Cells[mn - 1][fb - 1] = k;
            Rellenar4(v, mn, fb - 1, ca, k);
        }
    }
}
void Cargar4(TStringGrid* v, byte m, byte n, byte ca, byte &k)
{
    if (m * n > 0) {
        if (m * n == 1) {
            v->Cells[n - 1][m - 1] = k;
            Cargar4(v, m - 1, n - 1, ca, k);
        } else {
            Rellenar4(v, m, m - 1, ca, k);
            k++;
            Cargar4(v, m - 1, n - 1, ca, k);
        }
    }
}
void __fastcall TForm1::CARGAR41Click(TObject* Sender)
{
    byte k = 1;
    Cargar4(StringGrid3, StringGrid3->RowCount, StringGrid3->ColCount, 1, k);
}
//---------------------------------------------------------------------------
void RellenarSerp(TStringGrid* v, byte m, byte ca, byte cb, byte &k)
{
    if (cb > 0) {
        if ((m % 2) != 0) {
            v->Cells[ca - 1][m - 1] = k++;
            RellenarSerp(v, m, ca + 1, cb - 1, k);
        } else {
            v->Cells[cb - 1][m - 1] = k++;
            RellenarSerp(v, m, ca, cb - 1, k);
        }
    }
}
void CargarSerp(TStringGrid* v, byte m, byte ca, byte &k)
{
    if (m > 0) {
        CargarSerp(v, m - 1, ca, k);
        RellenarSerp(v, m, ca, v->ColCount, k);
    }
}
void __fastcall TForm1::CARGARSERPIENTE1Click(TObject* Sender)
{
    byte k = 1;
    CargarSerp(StringGrid3, StringGrid3->RowCount, 1, k);
}
//---------------------------------------------------------------------------
void RellenarSerp2(TStringGrid* v, byte m, byte ca, byte cb, byte &k)
{
    if (cb > 0) {
        if ((m % 2) != 0) {
            v->Cells[cb - 1][m - 1] = k++;
            RellenarSerp2(v, m, ca, cb - 1, k);
        } else {
            v->Cells[ca - 1][m - 1] = k++;
            RellenarSerp2(v, m, ca + 1, cb - 1, k);
        }
    }
}
void CargarSerp2(TStringGrid* v, byte m, byte ca, byte &k)
{
    if (m > 0) {
        CargarSerp2(v, m - 1, ca, k);
        RellenarSerp2(v, m, ca, v->ColCount, k);
    }
}
void __fastcall TForm1::CARGARSERPIENTE21Click(TObject* Sender)
{
    byte k = 1;
    CargarSerp2(StringGrid3, StringGrid3->RowCount, 1, k);
}
//---------------------------------------------------------------------------
void RellenarSerp3(TStringGrid* v, byte m, byte ca, byte cb, byte &k)
{
    if (cb > 0) {
        if ((m % 2) != 0) {
            v->Cells[ca - 1][m - 1] = k++;
            RellenarSerp3(v, m, ca + 1, cb - 1, k);
        } else {
            v->Cells[cb - 1][m - 1] = k++;
            RellenarSerp3(v, m, ca, cb - 1, k);
        }
    }
}
void CargarSerp3(TStringGrid* v, byte m, byte ca, byte &k)
{
    if (m > 0) {
        RellenarSerp3(v, m, ca, v->ColCount, k);
        CargarSerp3(v, m - 1, ca, k);
    }
}
void __fastcall TForm1::CARGARSERPIENTE31Click(TObject* Sender)
{
    byte k = 1;
    CargarSerp3(StringGrid3, StringGrid3->RowCount, 1, k);
}
//---------------------------------------------------------------------------
void RellenarSerp4(TStringGrid* v, byte m, byte ca, byte cb, byte &k)
{
    if (cb > 0) {
        if ((m % 2) != 0) {
            v->Cells[cb - 1][m - 1] = k++;
            RellenarSerp4(v, m, ca, cb - 1, k);
        } else {
            v->Cells[ca - 1][m - 1] = k++;
            RellenarSerp4(v, m, ca + 1, cb - 1, k);
        }
    }
}
void CargarSerp4(TStringGrid* v, byte m, byte ca, byte &k)
{
    if (m > 0) {
        RellenarSerp4(v, m, ca, v->ColCount, k);
        CargarSerp4(v, m - 1, ca, k);
    }
}
void __fastcall TForm1::CARGARSERP41Click(TObject* Sender)
{
    byte k = 1;
    CargarSerp4(StringGrid3, StringGrid3->RowCount, 1, k);
}
//---------------------------------------------------------------------------
void RellenarSerpg(TStringGrid* v, byte m, byte n, Word &k)
{
    if (n > 0) {
		if ((v->ColCount - m) % 2 != 0) {
            RellenarSerpg(v, m, n - 1, k);
            v->Cells[n - 1][m] = k;
            k++;
        } else {
            v->Cells[n - 1][m] = k;
            k++;
            RellenarSerpg(v, m, n - 1, k);
        }
    }
}

void SerpDiagonal(TStringGrid* v, byte m, byte n, Word &k)
{
    if (m > 0) {
		RellenarSerpg(v, m - 1, n, k);
		SerpDiagonal(v, m - 1, n - 1, k);
    }
}
void __fastcall TForm1::SERPIENTEDIAG1Click(TObject* Sender)
{
    Word k = 1;
    SerpDiagonal(StringGrid3, StringGrid3->RowCount, StringGrid3->ColCount, k);
}
//---------------------------------------------------------------------------

