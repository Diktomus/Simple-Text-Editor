#include "text_editor.h"
#include "test_runner.h"


void TypeText(TextEditor& text_editor, const string& text) {
  for(char c : text) {
    text_editor.Insert(c);
  }
}

void TestEditing() {
{
  TextEditor text_editor;

  const size_t text_len = 12;
  const size_t first_part_len = 7;
  TypeText(text_editor, "hello, world");
  for(size_t i = 0; i < text_len; ++i) {
    text_editor.Left();
  }
  text_editor.Cut(first_part_len);
  for(size_t i = 0; i < text_len - first_part_len; ++i) {
    text_editor.Right();
  }
  TypeText(text_editor, ", ");
  text_editor.Paste();
  text_editor.Left();
  text_editor.Left();
  text_editor.Cut(3);
  
  ASSERT_EQUAL(text_editor.GetText(), "world, hello");
}
{
  TextEditor text_editor;
  
  TypeText(text_editor, "misprnit");
  text_editor.Left();
  text_editor.Left();
  text_editor.Left();
  text_editor.Cut(1);
  text_editor.Right();
  text_editor.Paste();
  
  ASSERT_EQUAL(text_editor.GetText(), "misprint");
}
}

void TestReverse() {
  TextEditor text_editor;

  const string text = "esreveR";
  for(char c : text) {
    text_editor.Insert(c);
    text_editor.Left();
  }
  
  ASSERT_EQUAL(text_editor.GetText(), "Reverse");
}

void TestNoText() {
  TextEditor text_editor;
  ASSERT_EQUAL(text_editor.GetText(), "");
  
  text_editor.Left();
  text_editor.Left();
  text_editor.Right();
  text_editor.Right();
  text_editor.Copy(0);
  text_editor.Cut(0);
  text_editor.Paste();
  
  ASSERT_EQUAL(text_editor.GetText(), "");
}

void TestEmptyBuffer() {
  TextEditor text_editor;

  text_editor.Paste();
  TypeText(text_editor, "example");
  text_editor.Left();
  text_editor.Left();
  text_editor.Paste();
  text_editor.Right();
  text_editor.Paste();
  text_editor.Copy(0);
  text_editor.Paste();
  text_editor.Left();
  text_editor.Cut(0);
  text_editor.Paste();
  
  ASSERT_EQUAL(text_editor.GetText(), "example");
}


int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  return 0;
}