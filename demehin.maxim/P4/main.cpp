int main()
{
  constexpr size_t base_size = 100;
  char* str = nullptr;
  try
  {
    str = new char[base_size);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }




  delete[] str;
}
