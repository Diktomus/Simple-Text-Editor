#pragma once

#include <string>

using namespace std;

class TextEditor {
public:
  TextEditor()
  : pos(0)
  , pos_end(MAX_TEXT_LENGHT - 1)
  , text_size(0)
  , buffer_size(0)
  {
    text.resize(MAX_TEXT_LENGHT);
    buffer.resize(MAX_TEXT_LENGHT);
  }

  void Left();
  void Right();
  void Insert(char token);
  void Cut(size_t tokens);
  void Copy(size_t tokens);
  void Paste();
  string GetText() const;

private:
  size_t MAX_TEXT_LENGHT = 1000000;
  size_t pos_end;
  size_t pos;
  size_t text_size;
  size_t buffer_size;
  string text;
  string buffer;
};