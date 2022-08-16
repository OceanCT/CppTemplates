import json
# 将模板加入readme.md
class template:
    def __init__(self,filename:str,description:str):
        self.filename = filename
        self.description = description
    def __repr__(self,):
        dic = {}
        dic[self.filename] = self.description
        return dic.__str__()
def cmp(x:template):
    return x.filename

with open('templates/templates.json','r',encoding='utf8') as f:
    templates = json.load(f)
template_lis = []
for i in templates.items():
    template_lis.append(template(i[0],i[1]))
template_lis.sort(key=cmp)
with open('readme.md','r',encoding='utf8') as f:
    readme_str = f.read()
target_str = '# 模板对应关系'
readme_str = readme_str[:readme_str.find(target_str)]+target_str+'\n\n'
for i in template_lis:
    readme_str+=i.filename+' --'+i.description+'\n\n'
with open('readme.md','w',encoding='utf8') as f:
    f.write(readme_str)
# 生成index.md
index_str = ""
for i in template_lis:
    index_str+='# '+i.description+"\n\n```cpp\n"
    with open('templates/'+i.filename,'r',encoding='utf8') as f:
        index_str+=f.read()
    index_str+="\n```\n\n\n\n"
with open('index.md','w',encoding='utf-8') as f:
    f.write(index_str)