char * brevnov::getline(std::istream& in, char stop)
{
  std::size_t max_size = 50;
  char * line = new char[max_size + 1];
  std::size_t current_size = 0;
  char c = '\0';
  std::noskipws(in);
  while ((in >> c) && (c != '\n'))
  {
    
  }
  std::skipws(in);
  return line;
}
