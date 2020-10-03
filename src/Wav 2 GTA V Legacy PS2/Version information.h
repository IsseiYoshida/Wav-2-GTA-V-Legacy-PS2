//---------------------------------------------------------------------------

/*


	Data: 21/08/2020
	Hora: 12:49
	Pa�s: Brasil
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



/*
Fun��o para obter os valores da vers�o de uma DLL ou execultavel
*/
System::AnsiString __fastcall Get_Build_version(const char *EXE)
{

	DWORD Tamanho = 0;
	BYTE *Obter_informa��es_da_vers�o = NULL;
	VS_FIXEDFILEINFO *Informa��es_do_arquivo = NULL;
	UINT Tamanho_das_informa��es_do_arquivo = 0;


	/*Obtem o tamanho da DLL ou execultavel*/
	Tamanho = GetFileVersionInfoSizeA(EXE, NULL);
	/* se o tamanho for 0 deu erro */
	if ( Tamanho == 0 )
	{
	 /*N�o � poss�vel Obter os valores retona desconhecido*/
	 return "Unknown";
	}

	/*Cria um novo BYTE com o mesmo tamanho do valor da variavel Tamanho*/
	Obter_informa��es_da_vers�o = new BYTE[Tamanho];

	/*Obtem as informa��es do Arquivo*/
	if (!GetFileVersionInfoA(EXE, 0,
	Tamanho, Obter_informa��es_da_vers�o))
	{
	/*Deleta Obter_informa��es_da_vers�o*/
	delete[] Obter_informa��es_da_vers�o;
	}

	/*Recupera informa��es de vers�o especificadas do recurso de
	informa��es de vers�o especificado.*/
	if ( !VerQueryValue( Obter_informa��es_da_vers�o, TEXT("\\"),
	(LPVOID*) &Informa��es_do_arquivo, &Tamanho_das_informa��es_do_arquivo))
	{
	/*Deleta Obter_informa��es_da_vers�o*/
	delete[] Obter_informa��es_da_vers�o;
	}

	/*Deleta Obter_informa��es_da_vers�o*/
	delete[] Obter_informa��es_da_vers�o;

	System::AnsiString Formatar;

	int A = (Informa��es_do_arquivo->dwFileVersionMS >> 16) & 0xff;
	int B = (Informa��es_do_arquivo->dwFileVersionMS >> 0) & 0xff;
	int C = (Informa��es_do_arquivo->dwFileVersionLS >>  16) & 0xff;
	int D = (Informa��es_do_arquivo->dwFileVersionLS >>  0) & 0xff;

	 /*Formata os valores para o retorno*/
	Formatar.printf("%d.%d.%d.%d", A, B, C, D);


	return Formatar;
}
//---------------------------------------------------------------------------
/* Repassa os novos valores para o Caption do Form1 */
System::AnsiString __fastcall OPLUtil_Title_Form(const char *EXE)
{
  System::AnsiString Version;

  #ifdef _WIN32
  Version = Get_Build_version(EXE) + " - 32Bit";
  #endif

  #ifdef _WIN64
  Version = Get_Build_version(EXE) + " - 64Bit";
  #endif

  System::AnsiString Result =
  L"Wav 2 GTA V: Legacy PS2 " + Version +
  L" - by Issei Yoshida  |  https://www.facebook.com/Issei992";

  return Result;
}
