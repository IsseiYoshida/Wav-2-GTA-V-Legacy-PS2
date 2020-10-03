//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"

bool HexThread_Running;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
   HexThread_Running = FALSE;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

/*


	Data: 21/08/2020
	Hora: 12:49
	País: Brasil
	Author: Issei Yoshida
	E-Mail: issei.imouto@gmail.com
	Github: https://github.com/IsseiYoshida/OPLUtil
	PS2 HOME: https://www.ps2-home.com/forum/viewtopic.php?f=83&t=9319
	Facebook: https://www.facebook.com/Issei992


	Copyright (C) 2020  Issei Yoshida

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

//---------------------------------------------------------------------------

#include <windows.h>

#include <System.UITypes.hpp>

#include "Version information.h"

#include "frags01.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;


void Clear_LIST()
{
   int ColumnCount = Form1->StringGrid1->ColumnCount;

   for (int i = ColumnCount; i --> 0; ) {

	if (Form1->StringGrid1->Columns[i] != NULL)
	{
	 TFmxObject *DEL;
	 DEL = Form1->StringGrid1->Columns[i];
	 Form1->StringGrid1->RemoveObject(DEL);
	 DEL->DisposeOf();
	}

   }

   Form1->StringGrid1->Repaint();

   Application->ProcessMessages();

}


void ADD_TStringColumn()
{



  for (int Column = 0; Column < 3; Column++) {



	TStringColumn *SGD = new TStringColumn(Form1->StringGrid1);
	try
	{

	 TVarRec args[1] = { Column };

	 if (Column == 0) {

	  SGD->Name    = Format("SGD%.2d", args, 0);
	  SGD->Header  = "Wav File Name";
	  SGD->Width   = 200;
	 }
	 else
	 if (Column == 1)
	 {

	  SGD->Name    = Format("SGD%.2d", args, 0);
	  SGD->Header  = "Output Raw File Name";
	  SGD->Width   = 200;
	 }
	 else
	 if (Column == 2)
	 {
	  SGD->Name    = Format("SGD%.2d", args, 0);
	  SGD->Header  = "Wav Path";
	  SGD->Width   = 400;
	 }


	SGD->Enabled = True;
	SGD->Parent  = Form1->StringGrid1;

	//Form1->StringGrid1->BeginUpdate();

	SGD->DefaultTextSettings->WordWrap = True; // True for Multiline text
	SGD->Opacity = 1;
	SGD->DefaultTextSettings->HorzAlign = TTextAlign::Leading;
	SGD->DefaultTextSettings->VertAlign = TTextAlign::Center;
	SGD->DefaultTextSettings->Trimming = TTextTrimming::Character;

	SGD->DefaultTextSettings->Font->Family = "Times New Roman";
	SGD->DefaultTextSettings->Font->Style << TFontStyle::fsBold;
	//<< TFontStyle::fsItalic
	//<< TFontStyle::fsUnderline
	//<< TFontStyle::fsStrikeOut;

	SGD->DefaultTextSettings->Font->Size = 14;

    /*

    static const TAlphaColor Alpha = TAlphaColor(0xff000000);
    static const unsigned Aliceblue = unsigned(0xfff0f8ff);
    static const unsigned Antiquewhite = unsigned(0xfffaebd7);
    static const unsigned Aqua = unsigned(0xff00ffff);
    static const unsigned Aquamarine = unsigned(0xff7fffd4);
    static const unsigned Azure = unsigned(0xfff0ffff);
    static const unsigned Beige = unsigned(0xfff5f5dc);
    static const unsigned Bisque = unsigned(0xffffe4c4);
    static const unsigned Black = unsigned(0xff000000);
    static const unsigned Blanchedalmond = unsigned(0xffffebcd);
    static const unsigned Blue = unsigned(0xff0000ff);
    static const unsigned Blueviolet = unsigned(0xff8a2be2);
    static const unsigned Brown = unsigned(0xffa52a2a);
    static const unsigned Burlywood = unsigned(0xffdeb887);
    static const unsigned Cadetblue = unsigned(0xff5f9ea0);
    static const unsigned Chartreuse = unsigned(0xff7fff00);
    static const unsigned Chocolate = unsigned(0xffd2691e);
    static const unsigned Coral = unsigned(0xffff7f50);
    static const unsigned Cornflowerblue = unsigned(0xff6495ed);
    static const unsigned Cornsilk = unsigned(0xfffff8dc);
    static const unsigned Crimson = unsigned(0xffdc143c);
    static const unsigned Cyan = unsigned(0xff00ffff);
    static const unsigned Darkblue = unsigned(0xff00008b);
    static const unsigned Darkcyan = unsigned(0xff008b8b);
    static const unsigned Darkgoldenrod = unsigned(0xffb8860b);
    static const unsigned Darkgray = unsigned(0xffa9a9a9);
    static const unsigned Darkgreen = unsigned(0xff006400);
    static const unsigned Darkgrey = unsigned(0xffa9a9a9);
    static const unsigned Darkkhaki = unsigned(0xffbdb76b);
    static const unsigned Darkmagenta = unsigned(0xff8b008b);
    static const unsigned Darkolivegreen = unsigned(0xff556b2f);
    static const unsigned Darkorange = unsigned(0xffff8c00);
    static const unsigned Darkorchid = unsigned(0xff9932cc);
    static const unsigned Darkred = unsigned(0xff8b0000);
    static const unsigned Darksalmon = unsigned(0xffe9967a);
    static const unsigned Darkseagreen = unsigned(0xff8fbc8f);
    static const unsigned Darkslateblue = unsigned(0xff483d8b);
    static const unsigned Darkslategray = unsigned(0xff2f4f4f);
    static const unsigned Darkslategrey = unsigned(0xff2f4f4f);
    static const unsigned Darkturquoise = unsigned(0xff00ced1);
    static const unsigned Darkviolet = unsigned(0xff9400d3);
    static const unsigned Deeppink = unsigned(0xffff1493);
    static const unsigned Deepskyblue = unsigned(0xff00bfff);
    static const unsigned Dimgray = unsigned(0xff696969);
    static const unsigned Dimgrey = unsigned(0xff696969);
    static const unsigned Dodgerblue = unsigned(0xff1e90ff);
    static const unsigned Firebrick = unsigned(0xffb22222);
    static const unsigned Floralwhite = unsigned(0xfffffaf0);
    static const unsigned Forestgreen = unsigned(0xff228b22);
    static const unsigned Fuchsia = unsigned(0xffff00ff);
    static const unsigned Gainsboro = unsigned(0xffdcdcdc);
    static const unsigned Ghostwhite = unsigned(0xfff8f8ff);
    static const unsigned Gold = unsigned(0xffffd700);
    static const unsigned Goldenrod = unsigned(0xffdaa520);
    static const unsigned Gray = unsigned(0xff808080);
    static const unsigned Green = unsigned(0xff008000);
    static const unsigned Greenyellow = unsigned(0xffadff2f);
    static const unsigned Grey = unsigned(0xff808080);
    static const unsigned Honeydew = unsigned(0xfff0fff0);
    static const unsigned Hotpink = unsigned(0xffff69b4);
    static const unsigned Indianred = unsigned(0xffcd5c5c);
    static const unsigned Indigo = unsigned(0xff4b0082);
    static const unsigned Ivory = unsigned(0xfffffff0);
    static const unsigned Khaki = unsigned(0xfff0e68c);
    static const unsigned Lavender = unsigned(0xffe6e6fa);
    static const unsigned Lavenderblush = unsigned(0xfffff0f5);
    static const unsigned Lawngreen = unsigned(0xff7cfc00);
    static const unsigned Lemonchiffon = unsigned(0xfffffacd);
    static const unsigned Lightblue = unsigned(0xffadd8e6);
    static const unsigned Lightcoral = unsigned(0xfff08080);
    static const unsigned Lightcyan = unsigned(0xffe0ffff);
    static const unsigned Lightgoldenrodyellow = unsigned(0xfffafad2);
    static const unsigned Lightgray = unsigned(0xffd3d3d3);
    static const unsigned Lightgreen = unsigned(0xff90ee90);
    static const unsigned Lightgrey = unsigned(0xffd3d3d3);
    static const unsigned Lightpink = unsigned(0xffffb6c1);
    static const unsigned Lightsalmon = unsigned(0xffffa07a);
    static const unsigned Lightseagreen = unsigned(0xff20b2aa);
    static const unsigned Lightskyblue = unsigned(0xff87cefa);
    static const unsigned Lightslategray = unsigned(0xff778899);
    static const unsigned Lightslategrey = unsigned(0xff778899);
    static const unsigned Lightsteelblue = unsigned(0xffb0c4de);
    static const unsigned Lightyellow = unsigned(0xffffffe0);
    static const unsigned LtGray = unsigned(0xffc0c0c0);
    static const unsigned MedGray = unsigned(0xffa0a0a0);
    static const unsigned DkGray = unsigned(0xff808080);
    static const unsigned MoneyGreen = unsigned(0xffc0dcc0);
    static const unsigned LegacySkyBlue = unsigned(0xfff0caa6);
    static const unsigned Cream = unsigned(0xfff0fbff);
    static const unsigned Lime = unsigned(0xff00ff00);
    static const unsigned Limegreen = unsigned(0xff32cd32);
    static const unsigned Linen = unsigned(0xfffaf0e6);
    static const unsigned Magenta = unsigned(0xffff00ff);
    static const unsigned Maroon = unsigned(0xff800000);
    static const unsigned Mediumaquamarine = unsigned(0xff66cdaa);
    static const unsigned Mediumblue = unsigned(0xff0000cd);
    static const unsigned Mediumorchid = unsigned(0xffba55d3);
    static const unsigned Mediumpurple = unsigned(0xff9370db);
    static const unsigned Mediumseagreen = unsigned(0xff3cb371);
    static const unsigned Mediumslateblue = unsigned(0xff7b68ee);
    static const unsigned Mediumspringgreen = unsigned(0xff00fa9a);
    static const unsigned Mediumturquoise = unsigned(0xff48d1cc);
    static const unsigned Mediumvioletred = unsigned(0xffc71585);
    static const unsigned Midnightblue = unsigned(0xff191970);
    static const unsigned Mintcream = unsigned(0xfff5fffa);
	static const unsigned Mistyrose = unsigned(0xffffe4e1);
    static const unsigned Moccasin = unsigned(0xffffe4b5);
	static const unsigned Navajowhite = unsigned(0xffffdead);
	static const unsigned Navy = unsigned(0xff000080);
	static const unsigned Oldlace = unsigned(0xfffdf5e6);
    static const unsigned Olive = unsigned(0xff808000);
	static const unsigned Olivedrab = unsigned(0xff6b8e23);
	static const unsigned Orange = unsigned(0xffffa500);
    static const unsigned Orangered = unsigned(0xffff4500);
	static const unsigned Orchid = unsigned(0xffda70d6);
    static const unsigned Palegoldenrod = unsigned(0xffeee8aa);
	static const unsigned Palegreen = unsigned(0xff98fb98);
	static const unsigned Paleturquoise = unsigned(0xffafeeee);
	static const unsigned Palevioletred = unsigned(0xffdb7093);
	static const unsigned Papayawhip = unsigned(0xffffefd5);
	static const unsigned Peachpuff = unsigned(0xffffdab9);
	static const unsigned Peru = unsigned(0xffcd853f);
	static const unsigned Pink = unsigned(0xffffc0cb);
    static const unsigned Plum = unsigned(0xffdda0dd);
	static const unsigned Powderblue = unsigned(0xffb0e0e6);
	static const unsigned Purple = unsigned(0xff800080);
	static const unsigned Red = unsigned(0xffff0000);
	static const unsigned Rosybrown = unsigned(0xffbc8f8f);
	static const unsigned Royalblue = unsigned(0xff4169e1);
	static const unsigned Saddlebrown = unsigned(0xff8b4513);
	static const unsigned Salmon = unsigned(0xfffa8072);
	static const unsigned Sandybrown = unsigned(0xfff4a460);
	static const unsigned Seagreen = unsigned(0xff2e8b57);
	static const unsigned Seashell = unsigned(0xfffff5ee);
	static const unsigned Sienna = unsigned(0xffa0522d);
	static const unsigned Silver = unsigned(0xffc0c0c0);
	static const unsigned Skyblue = unsigned(0xff87ceeb);
	static const unsigned Slateblue = unsigned(0xff6a5acd);
	static const unsigned Slategray = unsigned(0xff708090);
	static const unsigned Slategrey = unsigned(0xff708090);
    static const unsigned Snow = unsigned(0xfffffafa);
    static const unsigned Springgreen = unsigned(0xff00ff7f);
	static const unsigned Steelblue = unsigned(0xff4682b4);
	static const unsigned Tan = unsigned(0xffd2b48c);
    static const unsigned Teal = unsigned(0xff008080);
    static const unsigned Thistle = unsigned(0xffd8bfd8);
	static const unsigned Tomato = unsigned(0xffff6347);
	static const unsigned Turquoise = unsigned(0xff40e0d0);
    static const unsigned Violet = unsigned(0xffee82ee);
	static const unsigned Wheat = unsigned(0xfff5deb3);
    static const unsigned White = unsigned(0xffffffff);
	static const unsigned Whitesmoke = unsigned(0xfff5f5f5);
	static const unsigned Yellow = unsigned(0xffffff00);
    static const unsigned Yellowgreen = unsigned(0xff9acd32);
	static const TAlphaColor Null = TAlphaColor(0x0);


*/
	SGD->DefaultTextSettings->FontColor = unsigned(0xFF32CD32);
	//TAlphaColor(00000000);

	//Form1->StringGrid1->EndUpdate();

	Form1->StringGrid1->Repaint();

	}
	catch( Exception& E )
	{
	 ShowMessage("Error: " + E.Message);
	}


  }

  int ColumnCount = Form1->StringGrid1->ColumnCount;

  for (int i = ColumnCount; i --> 0; ) {

	if (Form1->StringGrid1->Columns[i] != NULL)
	{

	 if (i == 0) {

	   Form1->StringGrid1->Columns[i]->Width = 200;
	 }
	 else
	 if (i == 1)
	 {
	   Form1->StringGrid1->Columns[i]->Width = 200;
	 }
	 else
	 if (i == 2)
	 {
	   Form1->StringGrid1->Columns[i]->Width = 200;
	 }

	}

  }

  Form1->StringGrid1->Repaint();

  Application->ProcessMessages();

}

void ShellExecute_MFAudio(String Prog, String CMD)
{

SHELLEXECUTEINFO ShExecInfo = {0};
ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
ShExecInfo.hwnd = NULL;
ShExecInfo.lpVerb = NULL;
ShExecInfo.lpFile = Prog.c_str();
ShExecInfo.lpParameters = CMD.c_str();
ShExecInfo.lpDirectory = NULL;
ShExecInfo.nShow = SW_SHOW;
ShExecInfo.hInstApp = NULL;
ShellExecuteEx(&ShExecInfo);
WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
CloseHandle(ShExecInfo.hProcess);

}

System::AnsiString ExtractName(System::AnsiString FileName) {

 System::AnsiString A, B;

 // extrai o nome do arquivo com extensão
 A = ExtractFileName(FileName);

 // extrai só a extensão do nome do arquivo
 B = ExtractFileExt(FileName);

 // deleta a extensão do nome do arquivo
 A = StringReplace(A, B, "", TReplaceFlags() << rfReplaceAll << rfIgnoreCase);

 return A;
}

void MKDIR(System::AnsiString Path) {

	/*Se o diretório não existe*/
	if (!DirectoryExists(Path)) {

	  /*Força Criar uma pasta*/
	  ForceDirectories(Path);
	}

}

u64 GetFileOffSet(const char *Input, u64 block)
{

  FILE *File_Input = fopen(Input, "rb");

  fseek(File_Input, 0, SEEK_END);
  u64 FileSize = ftell(File_Input);
  fseek(File_Input, 0, SEEK_SET);

  fclose(File_Input);
  File_Input = NULL;

  u64 Calculate = FileSize / block;

   u64 Total = Calculate;

  return Total;
}

void GTA(const char *Input, const char *Output)
{

   int CB = Form1->ComboBox2->ItemIndex;

  if (CB == 2) {

   /* começo do arquivo raw para corrigir o head */
   u64 Total_Offset = GetFileOffSet(Input, 16);

   FILE *File_Input = fopen(Input, "rb");
   FILE *File_Output = fopen(Output, "wb");

   for (u64 OffSet = 1; OffSet < Total_Offset; OffSet++) {

	 unsigned char ReadHex16Bytes[16] = { 0x00 };

	 fread(&ReadHex16Bytes, 1, 16, File_Input);

	 Application->ProcessMessages();

	 if ( OffSet == 1 ) {

	  ReadHex16Bytes[0x01] = 0x06;
	 }

	 if ( OffSet > 1 ) {

	  ReadHex16Bytes[0x01] = 0x02;
	 }

	 fwrite(&ReadHex16Bytes, 1, 16, File_Output);
   }

   fclose(File_Input);
   fclose(File_Output);
   File_Input = NULL;
   File_Output = NULL;
   /* Fim do arquivo raw com head corrigido */

   /* começo do arquivo raw para dar split de 64KB em 64KB */
   u64 Total_Offset_Split_Size = GetFileOffSet(Input, 65536);

   u64 Total_Offset_Split = Total_Offset_Split_Size + 2;

   System::AnsiString Path = Form1->Edit1->Text;
   System::AnsiString NAME = ExtractName(Output);
   System::AnsiString NewPath = Path + PathDelim + NAME;

   MKDIR(NewPath);

   FILE *Input_Split = fopen(Output, "rb");

   System::AnsiString VAG = Path + PathDelim + NAME + ".VAG";
   FILE *Output_Merge = fopen(VAG.c_str(), "wb");

   for (u64 OffSet = 1; OffSet < Total_Offset_Split; OffSet++) {

	TVarRec args[1] = { OffSet };

	System::AnsiString Split_File = NewPath +
	PathDelim + Format("frags%.2d.raw", args, 0);

	System::AnsiString Split_File_Copy = NewPath +
	PathDelim + Format("frags%.2d.Copy.raw", args, 0);

	System::AnsiString Split_FileN = NewPath +
	PathDelim + Format("frags%.2dn.raw", args, 0);

	FILE *Output_Split64KB = fopen(Split_File.c_str(), "wb");
	FILE *Output_Split64KB_Copy = fopen(Split_File_Copy.c_str(), "wb");
	FILE *Output_SplitN4KB = fopen(Split_FileN.c_str(), "wb");

	unsigned char Split64KB[65536] = { 0x00 };
	unsigned char Split4KB[4096] = { 0x00 };

	fread(&Split64KB, 1, 65536, Input_Split);

	Application->ProcessMessages();

	if (OffSet > 1)
	{

	   fwrite(&Split4KB, 1, 4096, Output_SplitN4KB);
	   fwrite(&Split4KB, 1, 4096, Output_Merge);
	}
	else
	{
	   fwrite(&frags01, 1, 8068, Output_SplitN4KB);
	   fwrite(&frags01, 1, 8068, Output_Merge);
	}

	fwrite(&Split64KB, 1, 65536, Output_Split64KB);
	fwrite(&Split64KB, 1, 65536, Output_Merge);

	fwrite(&Split64KB, 1, 65536, Output_Split64KB_Copy);
	fwrite(&Split64KB, 1, 65536, Output_Merge);

	if (OffSet == Total_Offset_Split -1)
	{

	  for (u64 i = OffSet; i < OffSet + 3; i++) {

	  TVarRec args[1] = { i };

	  System::AnsiString Split_FileNEXT = NewPath +
	  PathDelim + Format("frags%.2dn.raw", args, 0);

	  FILE *Output_SplitN4KBExtra = fopen(Split_FileNEXT.c_str(), "wb");

	  fwrite(&Split4KB, 1, 4096, Output_SplitN4KBExtra);
	  fwrite(&Split4KB, 1, 4096, Output_Merge);

	  fclose(Output_SplitN4KBExtra);
	  Output_SplitN4KBExtra = NULL;
	  }

	}

	fclose(Output_Split64KB);
	fclose(Output_Split64KB_Copy);
	fclose(Output_SplitN4KB);

	Output_Split64KB = NULL;
	Output_Split64KB_Copy = NULL;
	Output_SplitN4KB = NULL;
   }

   fclose(Input_Split);
   Input_Split = NULL;

   fclose(Output_Merge);
   Output_Merge = NULL;
   /* Fim do arquivo raw para dar split de 64KB em 64KB */
  }



  if (CB == 1) {

   /* começo do arquivo raw para corrigir o head */
   u64 Total_Offset = GetFileOffSet(Input, 16);

   FILE *File_Input = fopen(Input, "rb");
   FILE *File_Output = fopen(Output, "wb");

   for (u64 OffSet = 1; OffSet < Total_Offset; OffSet++) {

	 unsigned char ReadHex16Bytes[16] = { 0x00 };

	 fread(&ReadHex16Bytes, 1, 16, File_Input);

	 Application->ProcessMessages();

	 if ( OffSet == 1 ) {

	  ReadHex16Bytes[0x01] = 0x06;
	 }

	 if ( OffSet > 1 ) {

	  ReadHex16Bytes[0x01] = 0x02;
	 }

	 fwrite(&ReadHex16Bytes, 1, 16, File_Output);
   }

   fclose(File_Input);
   fclose(File_Output);
   File_Input = NULL;
   File_Output = NULL;
   /* Fim do arquivo raw com head corrigido */

   /* começo do arquivo raw para dar split de 64KB em 64KB */
   u64 Total_Offset_Split_Size = GetFileOffSet(Input, 65536);

   u64 Total_Offset_Split = Total_Offset_Split_Size + 2;

   System::AnsiString Path = Form1->Edit1->Text;
   System::AnsiString NAME = ExtractName(Output);
   System::AnsiString NewPath = Path + PathDelim + NAME;

   MKDIR(NewPath);

   FILE *Input_Split = fopen(Output, "rb");

   for (u64 OffSet = 1; OffSet < Total_Offset_Split; OffSet++) {

	TVarRec args[1] = { OffSet };

	System::AnsiString Split_File = NewPath +
	PathDelim + Format("frags%.2d.raw", args, 0);

	System::AnsiString Split_File_Copy = NewPath +
	PathDelim + Format("frags%.2d.Copy.raw", args, 0);

	System::AnsiString Split_FileN = NewPath +
	PathDelim + Format("frags%.2dn.raw", args, 0);

	FILE *Output_Split64KB = fopen(Split_File.c_str(), "wb");
	FILE *Output_Split64KB_Copy = fopen(Split_File_Copy.c_str(), "wb");
	FILE *Output_SplitN4KB = fopen(Split_FileN.c_str(), "wb");

	unsigned char Split64KB[65536] = { 0x00 };
	unsigned char Split4KB[4096] = { 0x00 };

	fread(&Split64KB, 1, 65536, Input_Split);

	Application->ProcessMessages();

	if (OffSet > 1)
	{

	   fwrite(&Split4KB, 1, 4096, Output_SplitN4KB);
	}
	else
	{
	   fwrite(&frags01, 1, 8068, Output_SplitN4KB);
	}

	fwrite(&Split64KB, 1, 65536, Output_Split64KB);

	fwrite(&Split64KB, 1, 65536, Output_Split64KB_Copy);

	if (OffSet == Total_Offset_Split -1)
	{

	  for (u64 i = OffSet; i < OffSet + 3; i++) {

	  TVarRec args[1] = { i };

	  System::AnsiString Split_FileNEXT = NewPath +
	  PathDelim + Format("frags%.2dn.raw", args, 0);

	  FILE *Output_SplitN4KBExtra = fopen(Split_FileNEXT.c_str(), "wb");

	  fwrite(&Split4KB, 1, 4096, Output_SplitN4KBExtra);

	  fclose(Output_SplitN4KBExtra);
	  Output_SplitN4KBExtra = NULL;
	  }

	}

	fclose(Output_Split64KB);
	fclose(Output_Split64KB_Copy);
	fclose(Output_SplitN4KB);

	Output_Split64KB = NULL;
	Output_Split64KB_Copy = NULL;
	Output_SplitN4KB = NULL;
   }

   fclose(Input_Split);
   Input_Split = NULL;
   /* Fim do arquivo raw para dar split de 64KB em 64KB */
  }


  if (CB == 0) {

   /* começo do arquivo raw para corrigir o head */
   u64 Total_Offset = GetFileOffSet(Input, 16);

   FILE *File_Input = fopen(Input, "rb");
   FILE *File_Output = fopen(Output, "wb");

   for (u64 OffSet = 1; OffSet < Total_Offset; OffSet++) {

	 unsigned char ReadHex16Bytes[16] = { 0x00 };

	 fread(&ReadHex16Bytes, 1, 16, File_Input);

	 Application->ProcessMessages();

	 if ( OffSet == 1 ) {

	  ReadHex16Bytes[0x01] = 0x06;
	 }

	 if ( OffSet > 1 ) {

	  ReadHex16Bytes[0x01] = 0x02;
	 }

	 fwrite(&ReadHex16Bytes, 1, 16, File_Output);
   }

   fclose(File_Input);
   fclose(File_Output);
   File_Input = NULL;
   File_Output = NULL;
   /* Fim do arquivo raw com head corrigido */

   /* começo do arquivo raw para dar split de 64KB em 64KB */
   u64 Total_Offset_Split_Size = GetFileOffSet(Input, 65536);

   u64 Total_Offset_Split = Total_Offset_Split_Size + 2;

   System::AnsiString Path = Form1->Edit1->Text;
   System::AnsiString NAME = ExtractName(Output);

   FILE *Input_Split = fopen(Output, "rb");

   System::AnsiString VAG = Path + PathDelim + NAME + ".VAG";
   FILE *Output_Merge = fopen(VAG.c_str(), "wb");

   for (u64 OffSet = 1; OffSet < Total_Offset_Split; OffSet++) {

	unsigned char Split64KB[65536] = { 0x00 };
	unsigned char Split4KB[4096] = { 0x00 };

	fread(&Split64KB, 1, 65536, Input_Split);

	Application->ProcessMessages();

	if (OffSet > 1)
	{
	   fwrite(&Split4KB, 1, 4096, Output_Merge);
	}
	else
	{
	   fwrite(&frags01, 1, 8068, Output_Merge);
	}

	fwrite(&Split64KB, 1, 65536, Output_Merge);

	fwrite(&Split64KB, 1, 65536, Output_Merge);

	if (OffSet == Total_Offset_Split -1)
	{

	  for (u64 i = OffSet; i < OffSet + 3; i++) {

	  fwrite(&Split4KB, 1, 4096, Output_Merge);
	  }

	}

   }

   fclose(Input_Split);
   Input_Split = NULL;

   fclose(Output_Merge);
   Output_Merge = NULL;
   /* Fim do arquivo raw para dar split de 64KB em 64KB */

   if (FileExists(Output))
   {
	 DeleteFile(Output);
   }

   if (FileExists(Input))
   {
	 DeleteFile(Input);
   }

  }


}

__fastcall HexThread::HexThread()
		: TThread(true)
 {
   FreeOnTerminate = true;
 }

//---------------------------------------------------------------------------

void __fastcall HexThread::Finished()
{

  HexThread_Running = FALSE;

  Form1->StringGrid1->Selected = 0;
}

void __fastcall HexThread::Execute()
{

  Synchronize([this](){

	int CB = Form1->ComboBox1->ItemIndex;

	String OTV;

	if (CB >= 0) {

		switch (CB) {

			case 0: OTV = "WAVU";
				break;
			case 1: OTV = "SS2U";
				break;
			case 2: OTV = "SS2C";
				break;
			case 3: OTV = "VAGC";
				break;
			case 4: OTV = "RAWU";
				break;
			case 5: OTV = "RAWC";
				break;
		}
	}

	//Valid command line options:

	System::AnsiString Path = Form1->Edit1->Text;
	String Prog = Form1->Edit2->Text;

	String IFV = Form1->Edit3->Text;
	String OFV = Form1->Edit4->Text;
	String ICV = Form1->Edit5->Text;
	String OCV = Form1->Edit6->Text;
	String IIV = Form1->Edit7->Text;
	String OIV = Form1->Edit8->Text;
	String IHV = Form1->Edit9->Text;


	String IF = " /IF" + IFV; // 22050  : IFnnnnn Input frequency
	String IC = " /IC" + ICV; // 2 or 1 : ICn Input channels
	String II = " /II" + IIV; // 10000  : IIxxxx Input interleave (hex)
	String IH = " /IH" + IHV; // 10000  : IHxxxx Input headerskip (hex)
	String OT = " /OT" + OTV; // RAWC   : OTtttt Output type (WAVU, VAGC, SS2U, SS2C, RAWU, RAWC)
	String OF = " /OF" + OFV; // 24000  : OFnnnnn Output frequency
	String OC = " /OC" + OCV; // 2 or 1 : OCn Output channels
	String OI = " /OI" + OIV; // 10000  : OIxxxx Output interleave (hex)

	int RowCount = Form1->StringGrid1->RowCount;

	for (int Row = 0; Row < RowCount; Row++) {

	 if (
	 (Form1->StringGrid1->Cells[0][Row].IsEmpty() == False) &&
	 (Form1->StringGrid1->Cells[1][Row].IsEmpty() == False) &&
	 (Form1->StringGrid1->Cells[2][Row].IsEmpty() == False))
	 {
	  Form1->StringGrid1->Selected = Row;

	  System::AnsiString WAV_NAME = Form1->StringGrid1->Cells[2][Row];

	  System::AnsiString NAME = Form1->StringGrid1->Cells[1][Row];

	  System::AnsiString RAW_NAME = Path + PathDelim + NAME + ".raw";

	  TVarRec args[1] = { 1 };

	  System::AnsiString RAW = Path + PathDelim + NAME +
	  Format("_head_consertado_%.2d.raw", args, 0);


	  String Input = " \"" + WAV_NAME + "\""; // "InputFile" Input file to play/convert

	  String OutInput = " \"" + RAW_NAME + "\""; // "OutputFile" Output file to convert to

	  String CMD =
	  IF +
	  IC +
	  II +
	  IH +
	  OT +
	  OF +
	  OC +
	  OI +
	  Input +
	  OutInput;

	  ShellExecute_MFAudio(Prog, CMD);

	  GTA(RAW_NAME.c_str(), RAW.c_str());

	 }

	}

	ShowMessage("Conversion complete");

  });

 Synchronize(Finished);
}



int Analysis_Struct_MFAudio(const char *ISO)
{
  int result;

  result = -1;

  FILE *File = NULL;

  unsigned char buffer[16] = {0};


  if ((File = fopen(ISO, "rb")) != NULL) {

	if (fseek(File, 0x0000A760, SEEK_SET) == 0) {


	   if (fread(buffer, 1, sizeof(buffer), File) == sizeof(buffer)) {

		   //MDFaudio v1.0: read in 0x0000A760
		   //0x00 to 0x0F: 21 10 CF 76 31 2E 31 7E D2 C9 F8 FF 4F 46 54 57
		   //aschii: !Ïv1.1~ÒÉøÿOFTW
		   if (
		   (buffer[0x00] == 0x21) &&
		   (buffer[0x01] == 0x10) &&
		   (buffer[0x02] == 0xCF) &&
		   (buffer[0x03] == 0x76) &&
		   (buffer[0x04] == 0x31) &&
		   (buffer[0x05] == 0x2E) &&
		   (buffer[0x06] == 0x31) &&
		   (buffer[0x07] == 0x7E) &&
		   (buffer[0x08] == 0xD2) &&
		   (buffer[0x09] == 0xC9) &&
		   (buffer[0x0A] == 0xF8) &&
		   (buffer[0x0B] == 0xFF) &&
		   (buffer[0x0C] == 0x4F) &&
		   (buffer[0x0D] == 0x46) &&
		   (buffer[0x0E] == 0x54) &&
		   (buffer[0x0F] == 0x57))
		   {
			 result = 0;
		   }



	   }

	}

  fclose(File);
  free(buffer);
  File = NULL;
  }


  return result;
}

void ADD_IN_LIST(
System::AnsiString WAV_NAME,
System::AnsiString RAW_NAME,
System::AnsiString WAV_Path)
{
   int RowCount = Form1->StringGrid1->RowCount;

   for (int Row = 0; Row < RowCount; Row++) {

	 if (
	 (Form1->StringGrid1->Cells[0][Row].IsEmpty() == True) &&
	 (Form1->StringGrid1->Cells[1][Row].IsEmpty() == True) &&
	 (Form1->StringGrid1->Cells[2][Row].IsEmpty() == True) )
	 {
	   Form1->StringGrid1->Selected = Row;

	   Form1->StringGrid1->Cells[0][Row] = WAV_NAME;
	   Form1->StringGrid1->Cells[1][Row] = RAW_NAME;
	   Form1->StringGrid1->Cells[2][Row] = WAV_Path;

	   break;
	 }

   }

}

void __fastcall TForm1::Button1Click(TObject *Sender)
{

  OpenDialog1->Options.Clear();

  OpenDialog1->Options
  << TOpenOption::ofHideReadOnly
  << TOpenOption::ofAllowMultiSelect
  << TOpenOption::ofFileMustExist
  << TOpenOption::ofEnableSizing;

  OpenDialog1->Title = "Select all wav files to convert";
  OpenDialog1->Filter = "WAVEform audio format (Wav) (*.wav)|**.WAV";

  OpenDialog1->FilterIndex = 0;

   if (OpenDialog1->Execute())
   {
	 Clear_LIST();

	 ADD_TStringColumn();

	 Form1->StringGrid1->RowCount = OpenDialog1->Files->Count;

	 Form1->StringGrid1->Repaint();

	 for (int I = 0; I < OpenDialog1->Files->Count; I ++)
	 {

	  System::AnsiString NAME = OpenDialog1->Files->Strings[I].c_str();

	  System::AnsiString WAV_NAME = ExtractName(NAME) + ".wav";
	  System::AnsiString RAW_NAME = ExtractName(NAME);
	  System::AnsiString WAV_Path = NAME;

	  ADD_IN_LIST(WAV_NAME, RAW_NAME, WAV_Path);

	 }

	 Form1->StringGrid1->Selected = 0;

	 Application->ProcessMessages();
   }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{


  System::String Path, Title;

  Title = L"choose the location to save the files.";

  SelectDirectory(Title,"", Path);

  Form1->Edit1->Text = Path;


}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

	if (Form1->Edit1->Text.IsEmpty() == True)
	{
	  ShowMessage("Error: No location was selected to save files.");

	  Abort();
	}

	if (Form1->Edit2->Text.IsEmpty() == True)
	{
	  ShowMessage("Error: Please select MFAudio v1.1 before converting the files.");

	  Abort();
	}


	if (HexThread_Running == FALSE) {


		HexThread_Running = TRUE;

		HexThread *NEWHexThread = new HexThread();

		// não precisa limpar após terminar
		NEWHexThread->FreeOnTerminate = True;

		// defina a prioridade para mais baixa do que o normal
		NEWHexThread->Priority = tpLower;

		// agora executa o TThread
		NEWHexThread->Start();

	}
	else
	{
	  ShowMessage("Error: The WAV to VAG conversion thread is still running.!");
	  ShowMessage("Error: close the program to release the conversion thread.!");
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{

  Clear_LIST();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

  System::AnsiString EXE = ParamStr(0);
  Form1->Caption = OPLUtil_Title_Form(EXE.c_str());

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{



  OpenDialog1->Options.Clear();

  OpenDialog1->Options
  << TOpenOption::ofHideReadOnly
  << TOpenOption::ofFileMustExist
  << TOpenOption::ofEnableSizing;

  OpenDialog1->Title = "Select MFAudio.exe";
  OpenDialog1->Filter = "MFAudio v1.1 (MFAudio) (*.exe)|**.EXE";

  OpenDialog1->FilterIndex = 0;


  if (OpenDialog1->Execute())
  {

	for (int I = 0; I < OpenDialog1->Files->Count; I ++)
    {
	  AnsiString MFAudio = OpenDialog1->Files->Strings[I].c_str();

	  Edit2->Text = MFAudio.c_str();

	  /*
	  if (Analysis_Struct_MFAudio(MFAudio.c_str()) > -1)
	  {
		Edit2->Text = MFAudio.c_str();
	  }
	  else
	  {
		ShowMessage
		(
		"Error: The Program you selected is invalid and does not contain the same structure as MFAudio v1.1, Please Select MFAudio v1.1"
		);
	  } */

	}

  }

}
//---------------------------------------------------------------------------
