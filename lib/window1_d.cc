/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : Luis Claudio Gamb�a Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

CJanela1::CJanela1 (void)
{
//window
  SetName (wxT("Janela1"));
  SetTitle (wxT("Hoo!"));
  SetX (50);
  SetY (50);
  SetVisible (0);
  SetWidth (800);
  SetHeight (500);
//  SetPopupMenu (&pmenu1);


//timer1
  timer1.SetName (wxT("timer1"));
  timer1.SetTime (10000);
  timer1.SetRunState (true);
  timer1.SetFOwner (this);
  timer1.EvOnTime = EVONTIME & CJanela1::timer1OnTime;


//button1
  button1.SetName (wxT("button1"));
  button1.SetColor (20, 255, 10);
  button1.SetX (80);
  button1.SetY (300);
  button1.SetText (wxT("Botao"));
  button1.SetBorder (1);
  button1.SetHint (wxT("button1"));
  button1.SetFOwner (this);
  button1.EvMouseButtonRelease = EVMOUSEBUTTONRELEASE  & CJanela1::button1MouseButtonRelease;
//button2
  button2.SetName (wxT("button2"));
  button2.SetColor (255, 20, 10);
  button2.SetX (80);
  button2.SetY (330);
  button2.SetText (wxT("l2"));
  button2.SetBorder (0);
  button2.SetHint (wxT("button2"));
  button2.SetFOwner (this);
  button2.EvMouseButtonPress = EVMOUSEBUTTONPRESS & CJanela1::button2MouseButtonRelease;
//button3
  button3.SetName (wxT("button3"));
  button3.SetColor (10, 20, 255);
  button3.SetX (80);
  button3.SetY (360);
  button3.SetText (wxT("botao3"));
  button3.SetBorder (5);
  button3.SetHint (wxT("button3"));
  button3.SetFOwner (this);
  button3.EvMouseButtonClick = EVMOUSEBUTTONCLICK & CJanela1::button3MouseButtonRelease;
//button4
  button4.SetName (wxT("button4"));
  button4.SetColor (20, 255, 10);
  button4.SetX (175);
  button4.SetY (300);
  button4.SetText (wxT("ABCDEF"));
  button4.SetBorder (1);
  button4.SetHint (wxT("button4"));
  button4.SetFOwner (this);
  button4.EvMouseButtonClick = EVMOUSEBUTTONCLICK & CJanela1::button1MouseButtonRelease;
//button5
  button5.SetName (wxT("button5"));
  button5.SetColor (255, 20, 10);
  button5.SetX (175);
  button5.SetY (330);
  button5.SetText (wxT("ABCDEF"));
  button5.SetBorder (0);
  button5.SetHint (wxT("button5"));
  button5.SetFOwner (this);
  button5.EvMouseButtonClick = EVMOUSEBUTTONCLICK & CJanela1::button2MouseButtonRelease;
//button6
  button6.SetName (wxT("button6"));
  button6.SetColor (10, 20, 255);
  button6.SetX (175);
  button6.SetY (360);
  button6.SetText (wxT("ABCDEF"));
  button6.SetBorder (5);
  button6.SetHint (wxT("button6"));
  button6.SetFOwner (this);
  button6.EvMouseButtonClick = EVMOUSEBUTTONCLICK & CJanela1::button3MouseButtonRelease;
  button6.EvOnFocusOut = EVONFOCUSOUT & CJanela1::Edit1Focus;

//edit1
  edit1.SetName (wxT("edit1"));
  edit1.SetX (30);
  edit1.SetY (30);
  edit1.SetAlign (CA_LEFT);
  edit1.SetText (wxT("NO"));
  edit1.SetText (wxT("ABCDEFGH"));
  edit1.SetFOwner (this);
  edit1.EvOnFocusOut = EVONFOCUSOUT & CJanela1::Edit1Focus;
//edit2
  edit2.SetName (wxT("edit2"));
  edit2.SetX (30);
  edit2.SetY (60);
  edit2.SetAlign (CA_CENTER);
  edit2.SetText (wxT("OK"));
  edit2.SetText (wxT("ABCDEFGH"));
  edit2.SetFOwner (this);
  edit2.EvOnFocusOut = EVONFOCUSOUT & CJanela1::Edit1Focus;
//edit3
  edit3.SetName (wxT("edit3"));
  edit3.SetX (30);
  edit3.SetY (90);
  edit3.SetAlign (CA_RIGHT);
  edit3.SetText (wxT("YES"));
  edit3.SetText (wxT("ABCDEFGH"));
  edit3.SetFOwner (this);
  edit3.EvOnFocusOut = EVONFOCUSOUT & CJanela1::Edit1Focus;

//checkbox1
  checkbox1.SetName (wxT("checkbox1"));
  checkbox1.SetX (240);
  checkbox1.SetY (30);
  checkbox1.SetText (wxT("Check"));
  checkbox1.SetColor (10, 20, 255);
  checkbox1.SetFOwner (this);
  checkbox1.EvOnCheckBox = EVONCHECKBOX & CJanela1::checkbox1_oncheckbox;
//checkbox2
  checkbox2.SetName (wxT("checkbox2"));
  checkbox2.SetX (240);
  checkbox2.SetY (60);
  checkbox2.SetText (wxT("Check2"));
//text1
  text1.SetName (wxT("text1"));
  text1.SetX (480);
  text1.SetY (20);
  text1.SetWidth (500);
  text1.SetHeight (500);
  text1.LoadFromFile (wxT("teste.txt"));

//label1
  label1.SetName (wxT("string1"));
  label1.SetAlign (CA_LEFT);
  label1.SetX (15);
  label1.SetY (120);
  label1.SetWidth (150);
  label1.SetHeight (30);
  label1.SetText (wxT("primeira linha atomica"));
  //label1.SetFont ("-adobe-times-bold-*-*-*-*-140-*-*-*-*-*-*");
  label1.SetColor (255, 0, 0);

//pmenu1
  pmenu1.SetName (wxT("pmenu1"));
  pmenu1.SetText (wxT("pmenu1"));
  
  pmenuitem1_1.SetText (wxT("_Copiar"));
  pmenuitem1_1.SetName (wxT("Copiar"));
  pmenuitem1_1.SetFOwner (this);
  pmenuitem1_1.EvMenuActive = EVMENUACTIVE & CJanela1::button3MouseButtonRelease;
  pmenuitem1_2.SetText (wxT("_Recortar"));
  pmenuitem1_2.SetName (wxT("Recortar"));
  pmenuitem1_2.SetFOwner (this);
  pmenuitem1_2.EvMenuActive = EVMENUACTIVE & CJanela1::pmenuitem1_2MouseButtonPress;
  pmenuitem1_3.SetText (wxT("_Colar"));
  pmenuitem1_3.SetName (wxT("Colar"));
  pmenuitem1_3.SetFOwner (this);
  pmenuitem1_3.EvMenuActive = EVMENUACTIVE & CJanela1::pmenuitem1_3MouseButtonPress;
//pmenu2
  pmenu2.SetName (wxT("pmenu2"));
  pmenu2.SetText (wxT("pmenu2"));

  pmenuitem2_1.SetText (wxT("_Abrir"));
  pmenuitem2_1.SetName (wxT("Abrir"));
  pmenuitem2_1.SetFOwner (this);
  pmenuitem2_2.SetText (wxT("_Salvar"));
  pmenuitem2_2.SetName (wxT("Salvar"));
  pmenuitem2_2.SetFOwner (this);
  pmenuitem2_2.EvMenuActive = EVMENUACTIVE & CJanela1::AjudaMouseButtonPress;
  pmenuitem2_3.SetText (wxT("_Sair"));
  pmenuitem2_3.SetName (wxT("Sair"));
  pmenuitem2_3.SetFOwner (this);
  pmenuitem2_3.EvMenuActive = EVMENUACTIVE & CJanela1::pmenuitem2_3MouseButtonPress;

//menu1
  menu1.SetName (wxT("menu1"));
//  menu1.SetColor (150, 20, 25);
  menui1.SetText (wxT("_File"));
  menui1.SetName (wxT("File"));
  
  menui2.SetText (wxT("_Editar"));
  menui2.SetName (wxT("Editar"));
  
  menui3.SetText (wxT("_Ajuda"));
  menui3.SetName (wxT("Ajuda"));

//toolbutton1
  toolbutton1.SetName (wxT("toolbutton1"));
  toolbutton1.SetX (10);
  toolbutton1.SetY (300);
  toolbutton1.SetImgFileName (wxT("ok2.png"));
  toolbutton1.SetFOwner (this);
  toolbutton1.EvMouseButtonPress = EVMOUSEBUTTONPRESS & CJanela1::button1MouseButtonRelease;

//xpmbutton1
  xpmbutton1.SetName (wxT("xpmbutton1"));
  xpmbutton1.SetX (10);
  xpmbutton1.SetY (400);
  xpmbutton1.SetText (wxT("Ok"));
  xpmbutton1.SetImgFileName (wxT("ok.png"));
  xpmbutton1.SetFOwner (this);
  xpmbutton1.EvMouseButtonPress = EVMOUSEBUTTONPRESS & CJanela1::button1MouseButtonRelease;

//filedialog1
  filedialog1.SetName (wxT("filedialog1"));
  filedialog1.SetFileName (wxT("teste.png"));
  filedialog1.SetType (wxOPEN);
  filedialog1.SetFilter (wxT("Image Files (*.png)|*.png"));

//dirdialog1
  dirdialog1.SetName (wxT("dirdialog1"));
  dirdialog1.SetDirName (wxT("~/"));
  dirdialog1.SetType (wxOPEN);

//list1
  list1.SetName (wxT("list1"));
  list1.SetX (300);
  list1.SetY (150);
  list1.SetFOwner (this);
  list1.EvListSelect = EVLISTSELECT & CJanela1::ListClick;
  list1.AddItem (wxT("first"));
  list1.AddItem (wxT("second"));
  list1.AddItem (wxT("third"));
  list1.AddItem (wxT("45678910123456"));
  list1.AddItem (wxT("cinco"));
  list1.AddItem (wxT("6"));
  list1.AddItem (wxT("7"));
  list1.AddItem (wxT("oito"));
  list1.AddItem (wxT("nine"));
  list1.AddItem (wxT("decimo"));
  list1.AddItem (wxT("onze"));
  list1.AddItem (wxT("twoelve"));
  list1.AddItem (wxT("1"));
  list1.AddItem (wxT("2"));
  list1.AddItem (wxT("3"));
  list1.AddItem (wxT("4"));
  list1.AddItem (wxT("5"));
  list1.AddItem (wxT("6"));
  list1.AddItem (wxT("7"));
  list1.AddItem (wxT("8"));
  list1.AddItem (wxT("penultimo"));
  list1.AddItem (wxT("ultimo"));

//filelist1
  filelist1.SetName (wxT("filelist1"));
  filelist1.SetX (260);
  filelist1.SetY (290);
  filelist1.SetWidth (200);
  filelist1.SetHeight (300);
  filelist1.SetFOwner (this);
  filelist1.EvFileListSelectFile = EVFILELISTSELECTFILE  & CJanela1::FileListOnFileSelected;

//scroll1
  scroll1.SetName (wxT("scrol1"));
  scroll1.SetX (100);
  scroll1.SetY (200);
  scroll1.SetType (st_horizontal);
  scroll1.SetRange (100);

//combo1
  combo1.SetName (wxT("combo1"));
  combo1.SetX (110);
  combo1.SetY (50);
  combo1.SetWidth (120);
  combo1.SetFOwner (this);
  combo1.EvOnComboChange = EVONCOMBOCHANGE & CJanela1::ComboChange;
  combo1.AddItem (wxT("um"));
  combo1.AddItem (wxT("dois"));
  combo1.AddItem (wxT("tres"));
  combo1.AddItem (wxT("quatro"));
  combo1.AddItem (wxT("cinco"));
  combo1.AddItem (wxT("seis"));
  combo1.AddItem (wxT("sete"));
  combo1.AddItem (wxT("oito"));
  combo1.AddItem (wxT("nove"));
  combo1.AddItem (wxT("dez"));
  combo1.AddItem (wxT("penultimo"));
  combo1.AddItem (wxT("ultimo"));

//image1
  image1.SetName (wxT("image1"));
  image1.SetX (150);
  image1.SetY (100);
  image1.SetWidth (100);
  image1.SetHeight (60);
  image1.SetImgFileName(wxT("../share/icons/splash.xpm"));
  //image1.SetImgFileName(wxT("/home/gamboa/MyDownloads/meus/LXRAD_WX/share/icons/splash.xpm"));


//draw1
  draw1.SetName (wxT("draw1"));
  draw1.SetX (5);
  draw1.SetY (140);
  draw1.SetWidth (60);
  draw1.SetHeight (60);


  CreateChild (&timer1);

  CreateChild (&filedialog1);
  
  CreateChild (&dirdialog1);

  CreateChild (&button1);

  CreateChild (&button2);
  CreateChild (&button3);
  CreateChild (&button4);
  CreateChild (&button5);
  CreateChild (&button6);


  CreateChild (&edit1);
  CreateChild (&edit2);
  CreateChild (&edit3);

  CreateChild (&checkbox1);
  CreateChild (&checkbox2);

  CreateChild (&text1);

  CreateChild (&label1);

  CreateChild (&menu1);
  
  menu1.CreateChild (&menui1);
  menu1.CreateChild (&menui2);
  menu1.CreateChild (&menui3);
  
  menu1.CreateChild (&pmenu1);
  pmenu1.CreateChild (&pmenuitem1_1);
  pmenu1.CreateChild (&pmenuitem1_2);
  pmenu1.CreateChild (&pmenuitem1_3);
  
  menu1.CreateChild (&pmenu2);
  pmenu2.CreateChild (&pmenuitem2_1);
  pmenu2.CreateChild (&pmenuitem2_2);
  pmenu2.CreateChild (&pmenuitem2_3);



  CreateChild (&toolbutton1);
  CreateChild (&xpmbutton1);

  CreateChild (&list1);
  
  CreateChild (&filelist1);
  
  CreateChild (&scroll1);

  CreateChild (&combo1);


  CreateChild (&image1);

  CreateChild (&draw1);

};
