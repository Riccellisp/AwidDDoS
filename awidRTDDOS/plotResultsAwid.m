function plotResultsAwid(correlation,threshold,entropy,variation,packetRate)
% keyboard;
    if(correlation<threshold)
%         There is an attack
        plot3(entropy,variation,packetRate, 'r--o');
        hold on
    else
%         there is a normal traffic
        plot3(entropy,variation,packetRate, 'b--o');
        hold on
    
    end

end