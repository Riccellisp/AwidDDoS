pth = '/home/riccelli/AwidDDoS/awidRTDDOS/';
liste = dir(strcat(pth,'*.txt'));
files = {liste.name};
for k = 1:numel(files);
  file{k} = strcat(pth,files{k});
  data{k} = importdata(file{k},' ',1000);
end