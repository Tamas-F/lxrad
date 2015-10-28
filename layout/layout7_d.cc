CPWindow7::CPWindow7(void)
{
  SetFOwner(this);
  SetClass(wxT("CPWindow"));
  SetName(wxT("window7"));
  SetTag(0);
  SetX(329);
  SetY(160);
  SetWidth(206);
  SetHeight(252);
  SetHint(wxT(""));
  SetEnable(1);
  SetVisible(0);
  SetPopupMenu(NULL);
  SetTitle(wxT("List"));
  SetOverrideRedirect(0);
  //button1
  button1.SetFOwner(this);
  button1.SetClass(wxT("CButton"));
  button1.SetName(wxT("button1"));
  button1.SetTag(0);
  button1.SetX(19);
  button1.SetY(147);
  button1.SetWidth(65);
  button1.SetHeight(28);
  button1.SetHint(wxT(""));
  button1.SetEnable(1);
  button1.SetVisible(1);
  button1.SetPopupMenu(NULL);
  button1.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow7::button1_EvMouseButtonPress;
  button1.SetText(wxT("Add"));
  CreateChild(&button1);
  //button2
  button2.SetFOwner(this);
  button2.SetClass(wxT("CButton"));
  button2.SetName(wxT("button2"));
  button2.SetTag(0);
  button2.SetX(95);
  button2.SetY(147);
  button2.SetWidth(65);
  button2.SetHeight(28);
  button2.SetHint(wxT(""));
  button2.SetEnable(1);
  button2.SetVisible(1);
  button2.SetPopupMenu(NULL);
  button2.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow7::button2_EvMouseButtonPress;
  button2.SetText(wxT("Remove"));
  CreateChild(&button2);
  //list1
  list1.SetFOwner(this);
  list1.SetClass(wxT("CList"));
  list1.SetName(wxT("list1"));
  list1.SetTag(0);
  list1.SetX(7);
  list1.SetY(7);
  list1.SetWidth(165);
  list1.SetHeight(133);
  list1.SetHint(wxT(""));
  list1.SetEnable(1);
  list1.SetVisible(1);
  list1.SetPopupMenu(NULL);
  list1.SetItems(wxT(""));
  CreateChild(&list1);
  //button3
  button3.SetFOwner(this);
  button3.SetClass(wxT("CButton"));
  button3.SetName(wxT("button3"));
  button3.SetTag(0);
  button3.SetX(19);
  button3.SetY(182);
  button3.SetWidth(65);
  button3.SetHeight(28);
  button3.SetHint(wxT(""));
  button3.SetEnable(1);
  button3.SetVisible(1);
  button3.SetPopupMenu(NULL);
  button3.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow7::button3_EvMouseButtonPress;
  button3.SetText(wxT("Clear"));
  CreateChild(&button3);
  //button4
  button4.SetFOwner(this);
  button4.SetClass(wxT("CButton"));
  button4.SetName(wxT("button4"));
  button4.SetTag(0);
  button4.SetX(95);
  button4.SetY(183);
  button4.SetWidth(65);
  button4.SetHeight(28);
  button4.SetHint(wxT(""));
  button4.SetEnable(1);
  button4.SetVisible(1);
  button4.SetPopupMenu(NULL);
  button4.EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow7::button4_EvMouseButtonPress;
  button4.SetText(wxT("Apply"));
  CreateChild(&button4);
};