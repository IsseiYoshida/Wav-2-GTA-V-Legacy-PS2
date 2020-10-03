//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Rtti.hpp>
#include <FMX.EditBox.hpp>
#include <FMX.NumberBox.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Memo.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TLayout *Layout1;
	TLayout *Layout2;
	TStyleBook *StyleBook1;
	TStringGrid *StringGrid1;
	TGroupBox *GroupBox1;
	TComboBox *ComboBox1;
	TLabel *Label3;
	TLabel *Label2;
	TLabel *Label1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TGroupBox *GroupBox2;
	TButton *Button1;
	TEdit *Edit1;
	TLabel *Label7;
	TButton *Button3;
	TButton *Button5;
	TLabel *Label8;
	TEdit *Edit2;
	TButton *Button4;
	TButton *Button2;
	TComboBox *ComboBox2;
	TLabel *Label6;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
	/*int Analysis_Struct_MFAudio(const char *ISO);
	void GTA(const char *RAW, const char *RAW2);
	void ShellExecute_MFAudio(String Prog, String CMD);
	void Clear_LIST();
	System::AnsiString ExtractName(System::AnsiString FileName);
    void __fastcall ADD_IN_LIST(
	System::AnsiString WAV_NAME,
	System::AnsiString RAW_NAME,
	System::AnsiString WAV_Path);
	void ADD_TStringColumn();
	void ADD_TStringColumn_HEX();*/

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif


class HexThread: public TThread
{
__published:    // IDE-managed Components

private:    // User declarations

protected:  // User declarations

  void __fastcall Execute();
  void __fastcall Finished();

public:     // User declarations

  __fastcall HexThread();

};
