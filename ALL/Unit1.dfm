object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 627
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  PixelsPerInch = 96
  TextHeight = 15
  object Edit1: TEdit
    Left = 160
    Top = 32
    Width = 121
    Height = 23
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 312
    Top = 32
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'Edit2'
  end
  object StringGrid1: TStringGrid
    Left = 160
    Top = 61
    Width = 417
    Height = 33
    DefaultColWidth = 32
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    ParentFont = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 24
    Top = 61
    Width = 122
    Height = 25
    Caption = 'DIMENSION VECTOR'
    TabOrder = 3
    OnClick = Button1Click
  end
  object StringGrid2: TStringGrid
    Left = 160
    Top = 100
    Width = 417
    Height = 34
    DefaultColWidth = 32
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
  end
  object Edit3: TEdit
    Left = 472
    Top = 32
    Width = 121
    Height = 23
    TabOrder = 5
    Text = 'Edit3'
  end
  object StringGrid3: TStringGrid
    Left = 120
    Top = 140
    Width = 499
    Height = 237
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
  end
  object Button2: TButton
    Left = 0
    Top = 216
    Width = 114
    Height = 25
    Caption = 'DIMENSION MATRIZ'
    TabOrder = 7
    OnClick = Button2Click
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 16
    object NUMERO1: TMenuItem
      Caption = 'NUMERO'
      object SUMADEPARES1: TMenuItem
        Caption = 'SUMADEPARES'
        OnClick = SUMADEPARES1Click
      end
      object MOVMAYORFINAL1: TMenuItem
        Caption = 'MOVMAYORFINAL'
        OnClick = MOVMAYORFINAL1Click
      end
      object VERFICARORDENADO1: TMenuItem
        Caption = 'VERFICARORDENADO'
        OnClick = VERFICARORDENADO1Click
      end
      object PARANTESDEUNIMPAR1: TMenuItem
        Caption = 'PARANTESDEUNIMPAR'
        OnClick = PARANTESDEUNIMPAR1Click
      end
      object SUMABINARIO1: TMenuItem
        Caption = 'SUMABINARIO'
      end
    end
    object NUMERO2: TMenuItem
      Caption = 'CADENA'
    end
    object VECTORES1: TMenuItem
      Caption = 'VECTORES'
      object CARGARRANDOM1: TMenuItem
        Caption = 'CARGARRANDOM'
        OnClick = CARGARRANDOM1Click
      end
      object CONTARPARES1: TMenuItem
        Caption = 'CONTARPARES'
        OnClick = CONTARPARES1Click
      end
      object ELIMINARDIG1: TMenuItem
        Caption = 'ELIMINARDATO'
        OnClick = ELIMINARDIG1Click
      end
      object INVERTIRENTREAYB1: TMenuItem
        Caption = 'INVERTIRENTREAYB'
        OnClick = INVERTIRENTREAYB1Click
      end
      object PONERXENPOS1: TMenuItem
        Caption = 'PONERXENPOS'
      end
      object VERFPALINDROME1: TMenuItem
        Caption = 'VERFPALINDROME'
        OnClick = VERFPALINDROME1Click
      end
      object FACTORIALNUM1: TMenuItem
        Caption = 'FACTORIALNUM'
        OnClick = FACTORIALNUM1Click
      end
      object NUMPRIM1: TMenuItem
        Caption = 'NUMPRIM'
        OnClick = NUMPRIM1Click
      end
      object INVERTIR1: TMenuItem
        Caption = 'INVERTIR'
        OnClick = INVERTIR1Click
      end
      object ELIMINARMDESEP1: TMenuItem
        Caption = 'ELIMINARMDESEP'
        OnClick = ELIMINARMDESEP1Click
      end
      object CARGARVOCALCAD1: TMenuItem
        Caption = 'CARGARVOCALCAD'
        OnClick = CARGARVOCALCAD1Click
      end
      object CARGARNUMORDEANDO1: TMenuItem
        Caption = 'CARGARNUMORDEANDO'
        OnClick = CARGARNUMORDEANDO1Click
      end
      object CARGARCONELEMDELABECE1: TMenuItem
        Caption = 'CARGARCONELEMDELABECE'
        OnClick = CARGARCONELEMDELABECE1Click
      end
    end
    object VECTORES2: TMenuItem
      Caption = 'MATRICES'
      object CARGAR1: TMenuItem
        Caption = 'CARGAR 1'
        OnClick = CARGAR1Click
      end
      object CARGAR21: TMenuItem
        Caption = 'CARGAR 2'
        OnClick = CARGAR21Click
      end
      object CARGAR31: TMenuItem
        Caption = 'CARGAR 3'
        OnClick = CARGAR31Click
      end
      object CARGAR41: TMenuItem
        Caption = 'CARGAR 4'
        OnClick = CARGAR41Click
      end
      object CARGARSERPIENTE1: TMenuItem
        Caption = 'CARGARSERPIENTE'
        OnClick = CARGARSERPIENTE1Click
      end
      object CARGARSERPIENTE21: TMenuItem
        Caption = 'CARGARSERPIENTE 2'
        OnClick = CARGARSERPIENTE21Click
      end
      object CARGARSERPIENTE31: TMenuItem
        Caption = 'CARGARSERPIENTE 3'
        OnClick = CARGARSERPIENTE31Click
      end
      object CARGARSERP41: TMenuItem
        Caption = 'CARGARSERPIENTE 4'
        OnClick = CARGARSERP41Click
      end
      object SERPIENTEDIAG1: TMenuItem
        Caption = 'SERPIENTEDIAG'
        OnClick = SERPIENTEDIAG1Click
      end
    end
  end
end
