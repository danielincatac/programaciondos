object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
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
    Left = 120
    Top = 192
    Width = 121
    Height = 23
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 368
    Top = 192
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'Edit2'
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 16
    object NUMERO1: TMenuItem
      Caption = 'NUMERO'
    end
    object NUMERO2: TMenuItem
      Caption = 'CADENA'
      object EJ11: TMenuItem
        Caption = 'EJ 1'
        OnClick = EJ11Click
      end
      object EJ21: TMenuItem
        Caption = 'EJ 2'
        OnClick = EJ21Click
      end
      object EJ22: TMenuItem
        Caption = 'EJ 3'
      end
      object EJ41: TMenuItem
        Caption = 'EJ 4'
        OnClick = EJ41Click
      end
      object EJ51: TMenuItem
        Caption = 'EJ 5'
        OnClick = EJ51Click
      end
    end
  end
end
