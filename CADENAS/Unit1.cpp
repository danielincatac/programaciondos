//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

AnsiString RepNum(byte a, byte b){
	AnsiString num;
	if(a==0){
		num="";
	}else{
		a--;
		num=RepNum(a,b);
		num=num+StrToInt(b);
	}
	return num;
}
AnsiString CadNumRep(Cardinal n){
	AnsiString num;
	if(n==0){
		num="";
	}else{
		byte d=n%10;
		n/=10;
		num=CadNumRep(n);
		num=num+RepNum(d,d);
	}
	return num;
}
void __fastcall TForm1::EJ51Click(TObject *Sender)
{
	Edit2->Text=CadNumRep(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void UltPriCad(AnsiString &cad){
	if(cad.Length()>=2){
		byte p=cad.LastDelimiter(" ");
		AnsiString pal=cad.SubString(p+1,cad.Length()-p);
		cad.SetLength(p-1);
		UltPriCad(cad);
		pal.Delete(1,1);
		pal.Delete(pal.Length(),1);
		cad=cad+" "+pal;
	}
}
void __fastcall TForm1::EJ52Click(TObject *Sender)
{
	AnsiString cad=Edit1->Text;
	UltPriCad(cad);
	Edit2->Text=cad;
}
//---------------------------------------------------------------------------
AnsiString DevolverVocal(AnsiString cad){
	AnsiString abc="aeiuoAEUOI�������U��";
	AnsiString vocal;
	if(cad.Length()==0){
		vocal="";
	}else{
		char voc=cad[cad.Length()];
		cad.Delete(cad.Length(),1);
		vocal=DevolverVocal(cad);
		if(abc.Pos(voc)>0)
			vocal=vocal+voc;
	}
	return vocal;
}
void __fastcall TForm1::EJ71Click(TObject *Sender)
{
	Edit2->Text=DevolverVocal(Edit1->Text);
}
//---------------------------------------------------------------------------

