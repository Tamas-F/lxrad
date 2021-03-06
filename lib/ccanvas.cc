/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001  Luis Claudio Gamboa Lopes

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

#include"../include/ccanvas.h"


// CCanvas_____________________________________________________________

CCanvas::CCanvas (void)
{
  LWidth = 0;
  SetClass (wxT("CCanvas"));
  DC=NULL;
  WDC=NULL;
  Pen=NULL;
  Brush=NULL;
  BitmapBuffer=NULL;
  Drawable=NULL;
  Bitmap=NULL;
  DirectDraw=true;
  Font= wxNullFont;  
};

CCanvas::~CCanvas (void)
{
  if(BitmapBuffer != NULL)
  {
    delete BitmapBuffer;
    BitmapBuffer = NULL;
  }
};

int
CCanvas::Create (wxWindow * drawable,int directdraw=1)
{
  DirectDraw=directdraw;
  Drawable = drawable;
   
  SetBgColor (0, 0, 0);
  SetFgColor (255, 255, 255);
  SetLineWidth (LWidth);

  Drawable->GetSize(&Width,&Height);
  
  if(!DirectDraw)
     BitmapBuffer= new  wxBitmap(Width, Height,  -1);
  
  return 1;
}

int
CCanvas::Create (wxWindow * drawable, wxBitmap * bitmap)
{
  DirectDraw=1;
  Bitmap=bitmap; 

  SetBgColor (0, 0, 0);
  SetFgColor (255, 255, 255);
  SetLineWidth (LWidth);

  Width=Bitmap->GetWidth();
  Height=Bitmap->GetHeight();
  
  return 1;
}

void
CCanvas::Destroy(void)
{
}

wxDC * 
CCanvas::GetDC(void)
{
  return  DC;
};

wxClientDC * 
CCanvas::GetWDC(void)
{
  return  WDC;
};
  
  
wxBitmap * 
CCanvas::GetBitmapBuffer(void)
{
  if(!DirectDraw) 
    return BitmapBuffer;
  else
    return NULL;
};

wxWindow * 
CCanvas::GetDrawable(void)
{
  return Drawable;
};

void 
CCanvas::SetBitmap(wxBitmap * bitmap,double xs, double ys)
{
  wxMemoryDC NDC;

  if(((BitmapBuffer != NULL) && (bitmap != NULL) && !DirectDraw )||(Bitmap != NULL))
  {
    Init();
    NDC.SelectObject(*bitmap);
    DC->SetUserScale(xs,ys);
    DC->Blit(0, 0, bitmap->GetWidth(),bitmap->GetHeight(),&NDC, 0, 0);
    DC->SetUserScale(1,1);
    End();
  }
};

void 
CCanvas::Init(void)
{
  int width,height;


  if(!DirectDraw)
  {
    Drawable->GetSize(&Width,&Height);
    width=BitmapBuffer->GetWidth();
    height=BitmapBuffer->GetHeight();


    if((Width != width)||(Height != height))
    {
      //copy content ?
      delete BitmapBuffer;
      BitmapBuffer= new  wxBitmap(Width, Height,  -1);
    }

    WDC =new  wxClientDC(Drawable);
    DC =new  wxMemoryDC();
    ((wxMemoryDC *)DC)->SelectObject(*BitmapBuffer);
  }
  else 
  {
    if(Drawable != NULL)	  
      DC = new wxClientDC(Drawable);
    else if(Bitmap != NULL)
    {	    
      DC = new wxMemoryDC();
      ((wxMemoryDC *)DC)->SelectObject(*Bitmap);
    }
  }

  Pen =new wxPen(DC->GetPen());
  Brush =new wxBrush(DC->GetBrush());
         

//  Font=wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT); 
  if(Font !=  wxNullFont)
     DC->SetFont (Font);
  
}

void 
CCanvas::Init(double sx,double sy)
{

  Init();

  DC->SetUserScale(sx,sy);
  
}

void 
CCanvas::ChangeScale(double sx,double sy)
{

  DC->SetUserScale(sx,sy);
  
}

void
CCanvas::End(void)
{
  int width,height;
  
  
  if(!DirectDraw)
  {
    Drawable->GetSize(&width,&height);
    if (WDC != NULL)
    {
       if(DC != NULL)
       {
         DC->SetUserScale(1.0,1.0);
         WDC->Blit(0, 0, width, height, DC, 0, 0);
       }
       delete WDC;
       WDC=NULL;
    };
  };

  if(DC != NULL)
  {
     delete DC;
     DC=NULL;
  }
  
  if(Pen != NULL)
  {
     delete Pen;
     Pen=NULL;
  }
  
  if(Brush != NULL)
  {
     delete Brush;
     Brush=NULL;
  }

}


void
CCanvas::SetFunction(wxRasterOperationMode  function)
{
  if (DC != NULL)
  {
    DC->SetLogicalFunction(function);
  };
};

void
CCanvas::SetColor (wxColor color)
{
  SetFgColor(color);
  SetBgColor(color);
}

void
CCanvas::SetColor (String color)
{
  SetFgColor(color);
  SetBgColor(color);
}

void
CCanvas::SetColor (uint r, uint g, uint b)
{
  SetFgColor(r,g,b);
  SetBgColor(r,g,b);
}

void
CCanvas::SetFgColor (wxColor color)
{
  FgColor = color;
  if (DC != NULL)
  {
    DC->SetTextForeground( FgColor);
    Pen->SetColour(FgColor);
    DC->SetPen(*Pen);
  } 
};

void
CCanvas::SetFgColor (String color)
{
  wxColourDatabase CB;

  FgColor=CB.Find(color.c_str ());

  if (DC != NULL)
  {
    DC->SetTextForeground( FgColor);
    Pen->SetColour(FgColor);
    DC->SetPen(*Pen);
  } 
};

void
CCanvas::SetFgColor (uint r, uint g, uint b)
{
  FgColor.Set(r,g,b);

  if (DC != NULL)
  {
    DC->SetTextForeground( FgColor);
    Pen->SetColour(FgColor);
    DC->SetPen(*Pen);
  } 
};

wxColor CCanvas::GetFgColor (void)
{
  return FgColor;
};

void
CCanvas::SetBgColor (wxColor color)
{
  BgColor = color;
  if (DC != NULL)
  {
    DC->SetTextBackground( BgColor);
    Brush->SetColour(BgColor);
    DC->SetBrush(*Brush);
  };
};

void
CCanvas::SetBgColor (String color)
{
  wxColourDatabase CB;

  BgColor=CB.Find(color.c_str ());

  if (DC != NULL)
  {
    DC->SetTextBackground( BgColor);
    Brush->SetColour(BgColor);
    DC->SetBrush(*Brush);
  };
};

void
CCanvas::SetBgColor (uint r, uint g, uint b)
{
  BgColor.Set(r,g,b);

  if (DC != NULL)
  {
    DC->SetTextBackground( BgColor);
    Brush->SetColour(BgColor);
    DC->SetBrush(*Brush);
  };
};

wxColor CCanvas::GetBgColor (void)
{
  return BgColor;
};

void
CCanvas::SetLineWidth (uint lwidth)
{
  LWidth = lwidth;

  if (DC != NULL)
  {
    Pen->SetWidth(LWidth);
    DC->SetPen(*Pen);
  };
};

uint CCanvas::GetLineWidth (void)
{
  return LWidth;
};

void
CCanvas::Point (int x, int y)
{
  if (DC != NULL) DC->DrawPoint ( x, y);
};

void
CCanvas::Points (wxPoint * points, int npoints)
{
//  gdk_draw_points (Drawable, GC, points, npoints);
  printf("Incomplete CCanvas::Points !\n");
};

void
CCanvas::Line (int x1_, int y1_, int x2_, int y2_)
{
  if (DC != NULL)DC->DrawLine(  x1_, y1_, x2_, y2_);
};

void
CCanvas::Lines (wxPoint * points, int npoints)
{
  if (DC != NULL)  DC->DrawLines(npoints, points);
};

void
CCanvas::Spline (wxPoint * points, int npoints)
{
  if (DC != NULL)  DC->DrawSpline(npoints, points);
};

/*
void
CCanvas::Segments (GdkSegment * segs, int nsegs)
{
  gdk_draw_segments (Drawable, GC, segs, nsegs);
};
*/

void
CCanvas::Rectangle (bool filled, int x, int y, int width, int height)
{
  if (DC != NULL)
  {
    if(filled)
      DC->SetBrush(*Brush);
    else  
      DC->SetBrush(*wxTRANSPARENT_BRUSH );
    
    DC-> DrawRectangle ( x, y, width, height);
  };
};

void
CCanvas::Arc (bool filled, int x, int y, int x1, int y1, int x2, int y2)
{
  if (DC != NULL)
  {
    if(filled)
      DC->SetBrush(*Brush);
    else  
      DC->SetBrush(*wxTRANSPARENT_BRUSH );
    DC->DrawArc ( x, y, x1, y1, x2, y2);
  }  
};

void
CCanvas::Polygon (bool filled, wxPoint * points, int npoints)
{
  if (DC != NULL)
  {
    if(filled)
      DC->SetBrush(*Brush);
    else  
      DC->SetBrush(*wxTRANSPARENT_BRUSH );
  
    DC->DrawPolygon (npoints, points);
  }  
};

void 
CCanvas::Circle (bool filled, int x, int y, int radius)
{
  if (DC != NULL)
  {
    if(filled)
      DC->SetBrush(*Brush);
    else  
      DC->SetBrush(*wxTRANSPARENT_BRUSH );
    DC->DrawCircle (x, y,radius);
  };
};
  
void 
CCanvas::Ellipse(bool filled,int x, int y, int width, int height)
{
  if (DC != NULL)
  {
    if(filled)
      DC->SetBrush(*Brush);
    else  
      DC->SetBrush(*wxTRANSPARENT_BRUSH );
    DC->DrawEllipse (x, y,width,height);
  }
};

void 
CCanvas::EllipticArc(bool filled,int x, int y, int width, int height, double start, double end)
{
  if (DC != NULL)
  {
    if(filled)
      DC->SetBrush(*Brush);
    else  
      DC->SetBrush(*wxTRANSPARENT_BRUSH );
    
    DC->DrawEllipticArc (x, y,width,height,start,end);
  }
};

  
void 
CCanvas::SetFont (wxFont font)
{
  Font=font;
  if (DC != NULL)DC->SetFont (font);
}


void 
CCanvas::Text (String str, int x, int y)
{
  if (DC != NULL)DC->DrawText (str,x,y);
};
  
void 
CCanvas::TextOnRect (String str, wxRect ret, unsigned int align )
{
  if (DC != NULL)
     DC->DrawLabel(str,ret, align);
}

void 
CCanvas::RotatedText (String str, int x, int y, int angle)
{
  if (DC != NULL)DC->DrawRotatedText (str,x,y,angle);
}


void 
CCanvas::FloodFill(int x, int y,wxColor color,wxFloodFillStyle  style)
{
  if (DC != NULL)DC->FloodFill(x, y, color, style);
};

  

void 
CCanvas::PutBitmap(wxBitmap * bitmap,int x, int y)
{
  if((bitmap != NULL) && (DC != NULL))
  {
     DC->DrawBitmap( *bitmap,x, y);
  }
};
