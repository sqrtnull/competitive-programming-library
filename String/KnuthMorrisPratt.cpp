/* <KMP> */
/* requires <ZAlgorithm> */

std::vector<int> KMP(std::vector<int> s, std::vector<int> w) {
    // first create table for w
    auto z = z_algorithm(w);
    std::vector<int> t(w.size()+1,0);
    t[0]=-1;
    for(int i=1;i<w.size();i++) {
        if(z[i]>0) {
            t[i+z[i]]=std::max(t[i+z[i]],z[i]);
            t[i]=-1;
        }
    }
    // search over s (mod)
    std::vector<int> ans;
    int k=0;
    for(int i=0;i<w.size()&&k<s.size();) {
        if(w[i]==s[(k+i)%s.size()]) i++;
        else {
            k=k+i-t[i];
            if(t[i]>=0) i=t[i];
            else i=0;
        }
        if(i==w.size()) {
            ans.emplace_back(k);
            k=k+i-t[i];
            i=t[i];
        }
    }
    return ans;
}

/* <KMP> */