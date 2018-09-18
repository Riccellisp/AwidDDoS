#include"defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>


void preProcessing (){
int i,aux;
aux = 0;

    //Awid dataset[600];
    Awid *dataset;
    char url[]="1",nome[20], linha[700];
	FILE *arq;

	double frame_time_epoch[600];
	double first_packet_window;
    char sourceIPs[600][18];
    char destinationIPs[600][18];



 

char    *typeOfFile(mode_t);
char    *permOfFile(mode_t);
void     outputStatInfo(char *, struct stat *);

    char *filename;
    struct stat st;


        if (lstat("1", &st) < 0) {
            perror("1");
            putchar('\n');
            return 0;
        }

        printf("o tamanho do arquivo eh %d",st.st_size);


	arq = fopen(url, "rb");

 	dataset=malloc(sizeof(Awid));

        if(dataset==NULL) {
      		printf("mao pode alocar\n");
		return 0;
	}
        printf("%d",sizeof(Awid));
        fflush(stdout);

	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
//		while( (fscanf(arq,"%[^,],%[^,],%[^,],%[^,],%[^,]\n", &testando.a, &testando.b,&testando.c, &testando.d,&testando.eP))!=EOF )
//			prcharf("%[^,] teve media %.2f\n", testando.a, testando.d);
	    
            fseek(arq,0,SEEK_SET);
            //for(i = 0;i<600;i++){
	    while(!feof(arq)) {
	    dataset=realloc(dataset, (i+2)*sizeof(Awid));
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

//            printf("%d,%d,%d\n",(strcmp(dataset[i].frame_time_epoch,"?") != 0),(strcmp(dataset[i].wlan_da,"?")!= 0),(strcmp(dataset[i].wlan_ra,"?")!= 0));


                if((strcmp(dataset[i].frame_time_epoch,"?") != 0) && (strcmp(dataset[i].wlan_da,"?")!= 0) && (strcmp(dataset[i].wlan_ra,"?")!= 0) ){
                	frame_time_epoch[aux] = atof(dataset[i].frame_time_epoch);
                	strcpy(sourceIPs[aux],dataset[i].wlan_sa);
                	strcpy(destinationIPs[aux],dataset[i].wlan_da);
                	aux++;
                	printf("%f\n", atof(dataset[i].frame_time_epoch));
                	printf("%s\n", destinationIPs);
                	printf("%s\n", sourceIPs);
            	}
            	else{
            	//printf("pulei\n");
                continue;

            	}

            }
		float  entropy;
		entropy = sourceIPsEntropy(sourceIPs,aux + 1);
		printf("%f\n",entropy);
    fclose(arq);

    }
}
