def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    ans = dict()
    for s in strs:
        key = "".join(sorted(list(s)))
        if key in ans:
            ans[key].append(s)
        else:
            ans[key] = [s]
    out = []
    for val in ans.values():
        out.append(val)
    return out