vector<string> anagrams(vector<string> &strs) {
  vector<string> v;
  unordered_map<string, vector<string> > dict;

  for (vector<string>::iterator it = strs.begin(); it != strs.end(); it ++) {
    string key = get_key(*it);
    if (!dict.count(key)) {
      v.clear();
      dict[key] = v;
    }
    dict[key].push_back(*it);
  }

  v.clear();
  for (unordered_map<string, vector<string> >::iterator it = dict.begin(); it != dict.end(); it ++) {
    if ((*it).second.size() > 1)
      v.insert(v.end(), (*it).second.begin(), (*it).second.end());
  }
  return v;
}

string get_key(string &str) {
  int counts[26] = {0};
  for (int i = 0; i < str.size(); i ++)
    counts[str[i] - 'a'] += 1;
  string key;
  for (int i = 0; i < 26; i ++) {
    key.insert(0, 1, i + 'a');
    while (counts[i] > 0) {
      key.insert(0, 1, counts[i] % 10 + '0');
      counts[i] /= 10;
    }
  }
  return key;
}
