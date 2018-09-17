#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdint.h>
#include <inttypes.h>
#include <math.h>

float prob1(char * sourceIPs, char *sourceIP, int len){
    int i,j,count;
    count = 0;
    for (i=0;i<len;i++){
       if (strcmp(*(sourceIPs + 18*i),sourceIP)){
    // conta
        count = count + 1;
       }

    }
    return count/len;

}

float sourceIPsEntropy (char *sourceIPs,int len){
//    size_t len = strlen(sourceIPs);
    int i,j;
    float result = 0.0;
    for (i=0;i<len;i++){
        for (j=0;j<18;j++){
        result = result + prob1(sourceIPs, *(sourceIPs + 18*i + j),&len) + log2(prob1(sourceIPs, *(sourceIPs + 18*i + j),&len));
        }
    }

    return result;


}




int isWindow (double t0, double t1, double windowLength){
    double tFinal;
    tFinal = t0 + windowLength;
    if (t1 <= tFinal)
        return 0;
        else
        return 1;
}

float sourceIPsVariation(char *sourceIPs){


}



int main(void)
{
    // Script parameters
    int windowLength = 1.0000;
    //

    typedef struct {
    int frame_interface_id;
    char 	     frame_dlt[1];
    char 	frame_offset_shift[1];
    char 	frame_time_epoch[16];
    char 	frame_time_delta[1];
    char 	frame_time_delta_displayed[1];
    char 	frame_time_relative[1];
    char  	frame_len[1];
    char  	frame_cap_len[1];
    char 	frame_marked[1]	;
    char 	frame_ignored[1]	;
    char 	radiotap_version[1]	;
    char 	radiotap_pad[1]	;
    char 	radiotap_length[1]	;//parei
    char 	radiotap_present_tsft[1]	;
    char 	radiotap_present_flags[1]	;
    char 	radiotap_present_rate[1]	;
    char 	radiotap_present_channel[1]	;
    char 	radiotap_present_fhss[1]	;
    char 	radiotap_present_dbm_antsignal[1]	;
    char 	radiotap_present_dbm_antnoise[1]	;
    char 	radiotap_present_lock_quality[1]	;
    char 	radiotap_present_tx_attenuation[1]	;
    char 	radiotap_present_db_tx_attenuation[1]	;
    char 	radiotap_present_dbm_tx_power[1]	;
    char 	radiotap_present_antenna[1]	;
    char 	radiotap_present_db_antsignal[1]	;
    char 	radiotap_present_db_antnoise[1]	;
    char 	radiotap_present_rxflags[1]	;
    char 	radiotap_present_xchannel[1]	;
    char 	radiotap_present_mcs[1]	;
    char 	radiotap_present_ampdu[1]	;
    char 	radiotap_present_vht[1]	;
    char	radiotap_present_reserved[1]	;
    char 	radiotap_present_rtap_ns[1]	;
    char 	radiotap_present_vendor_ns[1]	;
    char 	radiotap_present_ext[1]	;
    char 	radiotap_mactime[1]	;
    char 	radiotap_flags_cfp[1]	;
    char 	radiotap_flags_preamble[1]	;
    char 	radiotap_flags_wep[1]	;
    char 	radiotap_flags_frag[1]	;
    char 	radiotap_flags_fcs[1]	;
    char 	radiotap_flags_datapad[1]	;
    char 	radiotap_flags_badfcs[1]	;
    char 	radiotap_flags_shortgi[1]	;
    char 	radiotap_datarate[1]	;
    char  	radiotap_channel_freq[1]	;
    char 	radiotap_channel_type_turbo[1]	;
    char 	radiotap_channel_type_cck[1]	;
    char 	radiotap_channel_type_ofdm[1]	;
    char 	radiotap_channel_type_2ghz[1]	;
    char 	radiotap_channel_type_5ghz[1]	;
    char 	radiotap_channel_type_passive[1]	;
    char 	radiotap_channel_type_dynamic[1]	;
    char 	radiotap_channel_type_gfsk[1]	;
    char 	radiotap_channel_type_gsm[1]	;
    char 	radiotap_channel_type_sturbo[1]	;
    char 	radiotap_channel_type_half[1]	;
    char 	radiotap_channel_type_quarter[1]	;
    char 	radiotap_dbm_antsignal[1]	;
    char 	radiotap_antenna[1]	;
    char 	radiotap_rxflags_badplcp[1]	;
    char 	wlan_fc_type_subtype[1]	;
    char 	wlan_fc_version	[1];
    char 	wlan_fc_type[1]	;
    char 	wlan_fc_subtype[1]	;
    char 	wlan_fc_ds[1]	;
    char 	wlan_fc_frag[1]	;
    char 	wlan_fc_retry[1]	;
    char 	wlan_fc_pwrmgt[1]	;
    char 	wlan_fc_moredata[1]	;
    char 	wlan_fc_protected[1]	;
    char 	wlan_fc_order[1]	;
    char 	wlan_duration[1]	;
    char 	wlan_ra[18]	;//Receiver address	(Ethernet or other MAC address)
    char	wlan_da[18] 	; //Destination address (Ethernet or other MAC address)
    char 	wlan_ta[18]	; // Transmitter address (Ethernet or other MAC address)
    char 	wlan_sa[18]	;// Source address ((Ethernet or other MAC address))
    char 	wlan_bssid[18]	; //	BSS Id
    char 	wlan_frag[1]	;
    char 	wlan_seq[1]	;
    char 	wlan_bar_type[1]	;
    char 	wlan_ba_control_ackpolicy[1]	;
    char 	wlan_ba_control_multitid[1]	;
    char 	wlan_ba_control_cbitmap[1]	;
    char  	wlan_bar_compressed_tidinfo[1]	;
    char  	wlan_ba_bm[1]	;
    char 	wlan_fcs_good[1]	;
    char 	wlan_mgt_fixed_capabilities_ess[1]	;
    char 	wlan_mgt_fixed_capabilities_ibss[1]	;
    char    wlan_mgt_fixed_capabilities_cfpoll_ap[1]	;
    char 	wlan_mgt_fixed_capabilities_privacy[1]	;
    char 	wlan_mgt_fixed_capabilities_preamble[1]	;
    char 	wlan_mgt_fixed_capabilities_pbcc[1]	;
    char 	wlan_mgt_fixed_capabilities_agility	[1];
    char 	wlan_mgt_fixed_capabilities_spec_man[1]	;
    char 	wlan_mgt_fixed_capabilities_short_slot_time	[1];
    char 	wlan_mgt_fixed_capabilities_apsd[1]	;
    char 	wlan_mgt_fixed_capabilities_radio_measurement[1]	;
    char 	wlan_mgt_fixed_capabilities_dsss_ofdm[1]	;
    char 	wlan_mgt_fixed_capabilities_del_blk_ack[1]	;
    char 	wlan_mgt_fixed_capabilities_imm_blk_ack	[1];
    char  	wlan_mgt_fixed_listen_ival[1]	;
    char 	wlan_mgt_fixed_current_ap[1]	; // Current AP(Ethernet or MAC addres)
    char    wlan_mgt_fixed_status_code[1]	;
    char 	wlan_mgt_fixed_timestamp[1]	;
    char 	wlan_mgt_fixed_beacon[1]	;
    char  	wlan_mgt_fixed_aid[1]	;
    char 	wlan_mgt_fixed_reason_code[1]	;
    char 	wlan_mgt_fixed_auth_alg[1]	;
    char 	wlan_mgt_fixed_auth_seq	[1];
    char 	wlan_mgt_fixed_category_code[1]	;
    char 	wlan_mgt_fixed_htact[1]	;
    char 	wlan_mgt_fixed_chanwidth[1]	;
    char 	wlan_mgt_fixed_fragment[1]	;
    char  	wlan_mgt_fixed_sequence	[1];
    char	wlan_mgt_tagged_all[1] 	;
    char 	wlan_mgt_ssid[1]	;
    char 	wlan_mgt_ds_current_channel[1]	;
    char 	wlan_mgt_tim_dtim_count[1]	;
    char 	wlan_mgt_tim_dtim_period[1]	;
    char 	wlan_mgt_tim_bmapctl_multicast[1]	;
    char 	wlan_mgt_tim_bmapctl_offset[1]	;
    char 	wlan_mgt_country_info_environment[1]	;
    char  	wlan_mgt_rsn_version[1]	;
    char 	wlan_mgt_rsn_gcs_type[1]	;
    char 	wlan_mgt_rsn_pcs_count[1]	;
    char 	wlan_mgt_rsn_akms_count[1]	;
    char 	wlan_mgt_rsn_akms_type[1]	;
    char 	wlan_mgt_rsn_capabilities_preauth[1]	;
    char 	wlan_mgt_rsn_capabilities_no_pairwise[1]	;
    char 	wlan_mgt_rsn_capabilities_ptksa_replay_counter[1]	;
    char 	wlan_mgt_rsn_capabilities_gtksa_replay_counter[1]	;
    char 	wlan_mgt_rsn_capabilities_mfpr[1]	;
    char 	wlan_mgt_rsn_capabilities_mfpc[1]	;
    char 	wlan_mgt_rsn_capabilities_peerkey[1]	;
    char 	wlan_mgt_tcprep_trsmt_pow[1]	;
    char 	wlan_mgt_tcprep_link_mrg[1]	;
    char 	wlan_wep_iv[8]	;
    char 	wlan_wep_key[1]	;
    char 	wlan_wep_icv[1]	;
    char 	wlan_tkip_extiv[1]	;
    char 	wlan_ccmp_extiv[1]	;
    char 	wlan_qos_tid[1]	;
    char 	wlan_qos_priority[1]	;
    char 	wlan_qos_eosp[1]	;
    char 	wlan_qos_ack[6]	;
    char 	wlan_qos_amsdupresent[1]	;
    char 	wlan_qos_buf_state_indicated0[1]	;
    char 	a[1]	;
    char 	wlan_qos_txop_dur_req[1]	;
    char 	wlan_qos_buf_state_indicated1[1]	;
    char 	data_len[1]	;
    char 	classification[6]	;
    }Awid;
    int i;
    Awid dataset[600];
    char url[]="1",nome[20], linha[700];
	FILE *arq;

	double frame_time_epoch[600];
	double first_packet_window;
    char sourceIPs[600][18];
    char destinationIPs[600][18];

	arq = fopen(url, "rb");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
//		while( (fscanf(arq,"%[^,],%[^,],%[^,],%[^,],%[^,]\n", &testando.a, &testando.b,&testando.c, &testando.d,&testando.eP))!=EOF )
//			prcharf("%[^,] teve media %.2f\n", testando.a, testando.d);
            fseek(arq,0,SEEK_SET);
            for(i = 0;i<600;i++){
            fgets(linha,2000,arq);
            sscanf(linha,"%u,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%x,%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],\
            %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]\n",\
            &dataset[i].frame_interface_id,&dataset[i].frame_dlt,&dataset[i].frame_offset_shift,\
             &dataset[i].frame_time_epoch,&dataset[i].frame_time_delta,&dataset[i].frame_time_delta_displayed,&dataset[i].frame_time_relative,\
             &dataset[i].frame_len, &dataset[i].frame_cap_len,&dataset[i].frame_marked,&dataset[i].frame_ignored,&dataset[i].radiotap_version,\
            &dataset[i].radiotap_pad,&dataset[i].radiotap_length,&dataset[i].radiotap_present_tsft,&dataset[i].radiotap_present_flags,\
            &dataset[i].radiotap_present_rate,&dataset[i].radiotap_present_channel,&dataset[i].radiotap_present_fhss,\
            &dataset[i].radiotap_present_dbm_antsignal,&dataset[i].radiotap_present_dbm_antnoise,&dataset[i].radiotap_present_lock_quality,\
            &dataset[i].radiotap_present_tx_attenuation, &dataset[i].radiotap_present_db_tx_attenuation,\
            &dataset[i].radiotap_present_dbm_tx_power,&dataset[i].radiotap_present_antenna,&dataset[i].radiotap_present_db_antsignal,\
            &dataset[i].radiotap_present_db_antnoise,&dataset[i].radiotap_present_rxflags,&dataset[i].radiotap_present_xchannel,\
            &dataset[i].radiotap_present_mcs,&dataset[i].radiotap_present_ampdu, &dataset[i].radiotap_present_vht,\
            &dataset[i].radiotap_present_reserved,&dataset[i].radiotap_present_rtap_ns,&dataset[i].radiotap_present_vendor_ns,\
            &dataset[i].radiotap_present_ext,&dataset[i].radiotap_mactime,&dataset[i].radiotap_flags_cfp,\
            &dataset[i].radiotap_flags_preamble,&dataset[i].radiotap_flags_wep,&dataset[i].radiotap_flags_frag,\
            &dataset[i].radiotap_flags_fcs,&dataset[i].radiotap_flags_datapad,&dataset[i].radiotap_flags_badfcs,\
            &dataset[i].radiotap_flags_shortgi,&dataset[i].radiotap_datarate,&dataset[i].radiotap_channel_freq,\
            &dataset[i].radiotap_channel_type_turbo,&dataset[i].radiotap_channel_type_cck,&dataset[i].radiotap_channel_type_ofdm,\
            &dataset[i].radiotap_channel_type_2ghz,&dataset[i].radiotap_channel_type_5ghz,&dataset[i].radiotap_channel_type_passive,\
            &dataset[i].radiotap_channel_type_dynamic,&dataset[i].radiotap_channel_type_gfsk,\
            &dataset[i].radiotap_channel_type_gsm,&dataset[i].radiotap_channel_type_sturbo,&dataset[i].radiotap_channel_type_half,\
            &dataset[i].radiotap_channel_type_quarter,&dataset[i].radiotap_dbm_antsignal,&dataset[i].radiotap_antenna,\
            &dataset[i].radiotap_rxflags_badplcp,&dataset[i].wlan_fc_type_subtype,&dataset[i].wlan_fc_version,\
            &dataset[i].wlan_fc_type,&dataset[i].wlan_fc_subtype,&dataset[i].wlan_fc_ds,\
            &dataset[i].wlan_fc_frag,&dataset[i].wlan_fc_retry,&dataset[i].wlan_fc_pwrmgt,&dataset[i].wlan_fc_moredata,\
            &dataset[i].wlan_fc_protected,&dataset[i].wlan_fc_order,&dataset[i].wlan_duration,dataset[i].wlan_ra,\
            dataset[i].wlan_da,dataset[i].wlan_ta,dataset[i].wlan_sa,dataset[i].wlan_bssid,\
            &dataset[i].wlan_frag,&dataset[i].wlan_seq,&dataset[i].wlan_bar_type,&dataset[i].wlan_ba_control_ackpolicy,\
            &dataset[i].wlan_ba_control_multitid,&dataset[i].wlan_ba_control_cbitmap,&dataset[i].wlan_bar_compressed_tidinfo,\
            &dataset[i].wlan_ba_bm, &dataset[i].wlan_fcs_good,&dataset[i].wlan_mgt_fixed_capabilities_ess,\
            &dataset[i].wlan_mgt_fixed_capabilities_ibss,&dataset[i].wlan_mgt_fixed_capabilities_cfpoll_ap,\
            &dataset[i].wlan_mgt_fixed_capabilities_privacy,&dataset[i].wlan_mgt_fixed_capabilities_preamble,\
            &dataset[i].wlan_mgt_fixed_capabilities_pbcc,&dataset[i].wlan_mgt_fixed_capabilities_agility,\
            &dataset[i].wlan_mgt_fixed_capabilities_spec_man,&dataset[i].wlan_mgt_fixed_capabilities_short_slot_time,\
            &dataset[i].wlan_mgt_fixed_capabilities_apsd,&dataset[i].wlan_mgt_fixed_capabilities_radio_measurement,\
            &dataset[i].wlan_mgt_fixed_capabilities_dsss_ofdm,&dataset[i].wlan_mgt_fixed_capabilities_del_blk_ack,\
            &dataset[i].wlan_mgt_fixed_capabilities_imm_blk_ack,&dataset[i].wlan_mgt_fixed_listen_ival,\
            &dataset[i].wlan_mgt_fixed_current_ap,&dataset[i].wlan_mgt_fixed_status_code,&dataset[i].wlan_mgt_fixed_timestamp,\
            &dataset[i].wlan_mgt_fixed_beacon,&dataset[i].wlan_mgt_fixed_aid,&dataset[i].wlan_mgt_fixed_reason_code,\
            &dataset[i].wlan_mgt_fixed_auth_alg,&dataset[i].wlan_mgt_fixed_auth_seq,&dataset[i].wlan_mgt_fixed_category_code,\
            &dataset[i].wlan_mgt_fixed_htact,&dataset[i].wlan_mgt_fixed_chanwidth,&dataset[i].wlan_mgt_fixed_fragment,\
            &dataset[i].wlan_mgt_fixed_sequence,&dataset[i].wlan_mgt_tagged_all,&dataset[i].wlan_mgt_ssid,\
            &dataset[i].wlan_mgt_ds_current_channel,&dataset[i].wlan_mgt_tim_dtim_count,&dataset[i].wlan_mgt_tim_dtim_period,\
            &dataset[i].wlan_mgt_tim_bmapctl_multicast,&dataset[i].wlan_mgt_tim_bmapctl_offset,\
            &dataset[i].wlan_mgt_country_info_environment,&dataset[i].wlan_mgt_rsn_version,&dataset[i].wlan_mgt_rsn_gcs_type,\
            &dataset[i].wlan_mgt_rsn_pcs_count,&dataset[i].wlan_mgt_rsn_akms_count,&dataset[i].wlan_mgt_rsn_akms_type,\
            &dataset[i].wlan_mgt_rsn_capabilities_preauth,&dataset[i].wlan_mgt_rsn_capabilities_no_pairwise,\
            &dataset[i].wlan_mgt_rsn_capabilities_ptksa_replay_counter,&dataset[i].wlan_mgt_rsn_capabilities_gtksa_replay_counter,\
            dataset[i].wlan_mgt_rsn_capabilities_mfpr,&dataset[i].wlan_mgt_rsn_capabilities_mfpc,\
            &dataset[i].wlan_mgt_rsn_capabilities_peerkey,&dataset[i].wlan_mgt_tcprep_trsmt_pow,&dataset[i].wlan_mgt_tcprep_link_mrg,\
            &dataset[i].wlan_wep_iv,&dataset[i].wlan_wep_key,&dataset[i].wlan_wep_icv,&dataset[i].wlan_tkip_extiv,&dataset[i].wlan_ccmp_extiv,\
            &dataset[i].wlan_qos_tid,&dataset[i].wlan_qos_priority,&dataset[i].wlan_qos_eosp,&dataset[i].wlan_qos_ack,\
            &dataset[i].wlan_qos_amsdupresent,&dataset[i].wlan_qos_buf_state_indicated0,&dataset[i].a,\
            &dataset[i].wlan_qos_txop_dur_req,&dataset[i].wlan_qos_buf_state_indicated1,\
            &dataset[i].data_len,&dataset[i].classification);
            printf("%s\n", dataset[i].frame_time_epoch);
            printf("%s\n", dataset[i].wlan_da);
            printf("%s\n", dataset[i].wlan_ra);
            }
            int jk;
//            jk = strcmp(dataset[i].wlan_da,"?");
            //printf("%d\n", strcmp(dataset[i].wlan_da,"?") != 0);
            if(((strcmp(dataset[i].frame_time_epoch,"?") != 0)||(strcmp(dataset[i].wlan_da,"?")!= 0)||(strcmp(dataset[i].wlan_ra,"?")!= 0))){
            printf("%d\n",i);
//			prcharf("%[^,] teve media %.2f\n", testando.a, testando.d);
            frame_time_epoch[i] = atof(dataset[0].frame_time_epoch);
            first_packet_window = atof(dataset[i].frame_time_epoch);
            strcpy(sourceIPs[i],dataset[i].wlan_sa);
            strcpy(destinationIPs[i],dataset[i].wlan_da);

            int j;
            for(j=i+1;j<600;j++){

                //printf("%lf -  %lf  = %lf\n",atof(dataset[i].frame_time_epoch), first_packet_window, (atof(dataset[i].frame_time_epoch) - first_packet_window));
//                coi = isWindow(first_packet_window,(atof(dataset[i].frame_time_epoch)),windowLength);
//                if (coi != 0){
//                    printf("COISOU");
//
//                }
                frame_time_epoch[j] = atof(dataset[j].frame_time_epoch);

                if(!isWindow(first_packet_window,frame_time_epoch[j],windowLength)){
                    frame_time_epoch[j] = atof(dataset[j].frame_time_epoch);
                    strcpy(sourceIPs[j],dataset[j].wlan_sa);
                    strcpy(destinationIPs[j],dataset[j].wlan_da);
//                    printf("%s\n", sourceIPs[i]);
//                    printf("%s\n", destinationIPs[i]);
//                    printf("%lf\n", frame_time_epoch[i]);
                    int len;
                    len = sizeof(sourceIPs)/18;
                    sourceIPsEntropy(&sourceIPs,len);
                }

                    //else{
//                        int k,len;
//                        len = sizeof(sourceIPs)/18;
// CHAMAR FUNÇÃO QUE CALCULA A ENTROPIA,VARIAÇAO E TAL
                        //sourceIPsEntropy(&sourceIPs,len);
//                            break;
//add função que valida os campos do dataset
// se houver ? vai para o prox
                    //}

            }
                }

	fclose(arq);
	//printf("a coiisa eh: %c",dataset[i].classification);
	}


    return 0;
}
