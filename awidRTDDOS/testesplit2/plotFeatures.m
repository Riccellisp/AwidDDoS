new_data = cat(1, detection{:});
pktRate = [];
Var = [];
entropy = [];
acurracy = [];

for i = 1: length(new_data)
    pktRate = [pktRate new_data(i,6) ];
    Var = [Var new_data(i,7) ];
    entropy = [entropy new_data(i,8) ];
    acurracy = [acurracy new_data(i,5)];
end
pktRate =  cell2mat(pktRate);
Var =  cell2mat(Var);
entropy =  cell2mat(entropy);

plot(pktRate);
xlabel('number of windows');
ylabel('pktRate in Normal Traffic');
figure;
plot(Var);
xlabel('number of windows');
ylabel('Source IP Variation in Normal Traffic');
figure;
plot(entropy);
xlabel('number of windows');
ylabel('entropy in Normal Traffic');
figure;
plot(acurracy);
xlabel('number of windows');
ylabel('acurracy in Normal Traffic');
% a = size(detection);
% pktRate = [];
% for i =1:a(1)
%     for j = 1:a(2)
% %         keyboard;
%         if(~iscell(detection{i,j}{1,6}))
%         pktRate = [pktRate detection{i,j}{1,6}];
%         end
%     end
% end
% % dbstop if error