% % parameters
windowLength = 1;

dataset = textread('teste.txt', '%s', 'delimiter', ',','whitespace', '');
interval = 0:((length(dataset)/155)-1);
% for interval = 0:((length(dataset)/155)-1)
%     source(interval+1) = dataset(76 + 155*interval);
%     time(interval+1) = dataset(4 + 155*interval);
% end
sourceIPs = dataset(76 +155*[interval]);
time = str2double(dataset(4 +155*[interval]));

firstPacketWindowTime = time(1) + 1;
n = 0;



for i = 1:length(dataset)
    if(~isWindow(time(1),time(i),windowLength))
        n = n + 1;         
    else
        break;
%         disp(n);
    end
end
entr= entropy2([sourceIPs(1:n)]);
Var = length(unique([sourceIPs(1:n)]))/length(sourceIPs);
packetRate = n;
