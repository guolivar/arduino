auto fun_map(auto funct, auto items){
  
  for(int i = 0; i < sizeof(items); ++i){
    funct(items[i]);
  }
}

template<typename Function, typename... Arguments>
auto curry(Function function, Arguments... args) {
    return [=](auto... rest) {
        return function(args..., rest...);
    }
}
