#include <string>
#include <algorithm>
#include "text_editor.h"

using namespace std;

void TextEditor::Left() {
  if(pos != 0) {
    text[pos_end--] = text[--pos];
  }
}

void TextEditor::Right() {
  if(pos != text_size) {
    text[pos++] = text[pos_end + 1];
    pos_end++;
  }
}

void TextEditor::Insert(char token) {
  text[pos++] = token;
  text_size++;
}

void TextEditor::Cut(size_t tokens) {
  if(tokens >= (MAX_TEXT_LENGHT - 1 - pos_end)) {
    copy(begin(text) + pos_end + 1, end(text), begin(buffer));
    buffer_size = MAX_TEXT_LENGHT - 1 - pos_end;
    pos_end = MAX_TEXT_LENGHT - 1;
    text_size -= MAX_TEXT_LENGHT - 1 - pos_end;
  }
  else {
    copy(begin(text) + pos_end + 1, begin(text) + pos_end + 1 + tokens, begin(buffer));
    buffer_size = tokens;
    pos_end += tokens;
    text_size -= tokens;
  }
}

void TextEditor::Copy(size_t tokens) {
  if(tokens >= (MAX_TEXT_LENGHT - 1 - pos_end)) {
    copy(begin(text) + pos_end + 1, end(text), begin(buffer));
    buffer_size = MAX_TEXT_LENGHT - 1 - pos_end;
  }
  else {
    copy(begin(text) + pos_end + 1, begin(text) + pos_end + 1 + tokens, begin(buffer));
    buffer_size = tokens;
  }
}

void TextEditor::Paste() {
  copy(begin(buffer), begin(buffer) + buffer_size, begin(text) + pos);
  pos += buffer_size;
  text_size += buffer_size;
}

string TextEditor::GetText() const {
  return text.substr(0, pos) + text.substr(pos_end + 1);
}

