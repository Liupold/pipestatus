#include "deps.h"

vector <string>

parseTemplate(const string Template) {
		vector<string> init_data;
		size_t lb, rb, prb;
		lb = Template.find('<');
		rb = Template.find('>');
		prb = rb;
		init_data.push_back(Template.substr(0, lb));
		while (rb != string::npos || lb != string::npos) {
				init_data.push_back(Template.substr(lb, rb - lb + 1));
				lb = Template.find("<", lb+1);
				rb = Template.find(">", rb+1);
				init_data.push_back(Template.substr(prb + 1, lb - prb - 1));
				prb = rb;
		}
		return init_data;
}

void
parse_fifo_input(const string fifo_input,
		const vector<string> &init_data, vector<string> &curr_data) {
		size_t kv_sep_idx = fifo_input.find(':');

		if (kv_sep_idx == string::npos) {
				return; // invalid string is ignored.
		}
		string key = fifo_input.substr(0, kv_sep_idx);
		string value = fifo_input.substr(kv_sep_idx + 1, -1);

		for (size_t i=1; i <= init_data.size(); i+=2) {
				if (init_data[i] == "<" + key + ">") {
						curr_data[i] = value;
						break;
				}
				continue;
		}
}

void
cat_string(const vector<string> &curr_data) {
		for (size_t i=0; i < curr_data.size(); i++) {
				printf("%s", curr_data[i].c_str());
		}
		printf("\n");
		fflush(stdout);
}

