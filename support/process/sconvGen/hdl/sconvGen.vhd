library ieee;
	use	ieee.std_logic_1164.all;
	use	ieee.numeric_std.all;

entity sconvGen is
    generic (
        IMAGE_WIDTH 	: integer	:=	320;
        IN_SIZE 		: integer	:=	8;
        OUT1_SIZE 		: integer	:=	8;
        OUT2_SIZE 		: integer	:=	8;
        OUT3_SIZE 		: integer	:=	8;
        CLK_PROC_FREQ 	: integer 	:=  50000000
    );

    port (
        clk_proc 	: in    std_logic;
        reset_n 	: in    std_logic;

        ------------------------------ IN FLOW ---------------------------------
        in_data 	: in    std_logic_vector((IN_SIZE-1) downto 0);
        in_dv 		: in    std_logic;
        in_fv 		: in    std_logic;

        ----------------------------- OUT FLOW ---------------------------------
        out1_data  : out   std_logic_vector((OUT1_SIZE-1) downto 0);
        out1_dv    : out   std_logic;
        out1_fv    : out   std_logic;

        out2_data  : out   std_logic_vector((OUT2_SIZE-1) downto 0);
        out2_dv    : out   std_logic;
        out2_fv    : out   std_logic;

        out3_data  : out   std_logic_vector((OUT3_SIZE-1) downto 0);
        out3_dv    : out   std_logic;
        out3_fv    : out   std_logic;

        ------------------------------ Slaves ---------------------------------
        addr_rel_i 	: in    std_logic_vector(1 downto 0);
        wr_i 		: in    std_logic;
        rd_i 		: in    std_logic;
        datawr_i 	: in    std_logic_vector(31 downto 0);
        datard_o 	: out   std_logic_vector(31 downto 0)
    );

end sconvGen;

architecture structural of sconvGen is


    component sconvGen_slave
    port(
		clk_proc	: in  std_logic;
		reset_n		: in  std_logic;
		addr_rel_i	: in  std_logic_vector(1 downto 0);
		wr_i		: in  std_logic;
		rd_i		: in  std_logic;
		datawr_i	: in  std_logic_vector(31 downto 0);
		datard_o	: out std_logic_vector(31 downto 0);
		enable_o	: out std_logic
    );
    end component;

    component sconvGen_process
    generic(
        PIXEL_SIZE  :   integer;
        IMAGE_WIDTH :   integer
        );
    port(
        clk	        :	in 	std_logic;
        reset_n	    :	in	std_logic;
        enable	    :	in	std_logic;
        in_data     :	in 	std_logic_vector ((PIXEL_SIZE-1) downto 0);
        in_dv	    :	in	std_logic;
        in_fv	    :	in	std_logic;
        out1_data   :	out	std_logic_vector ((PIXEL_SIZE-1) downto 0);
        out1_dv	    :	out	std_logic;
        out1_fv	    :	out	std_logic;
        out2_data   :	out	std_logic_vector ((PIXEL_SIZE-1) downto 0);
        out2_dv	    :	out	std_logic;
        out2_fv	    :	out	std_logic;
        out3_data   :	out	std_logic_vector ((PIXEL_SIZE-1) downto 0);
        out3_dv	    :	out	std_logic;
        out3_fv	    :	out	std_logic

    );
    end component;

    signal enable_s : std_logic;

    begin
        slave_inst : sconvGen_slave
        port map
        (
            clk_proc	=> clk_proc,
            reset_n		=> reset_n,
            addr_rel_i	=> addr_rel_i,
            wr_i		=> wr_i,
            rd_i		=> rd_i,
            datawr_i	=> datawr_i,
            datard_o	=> datard_o,
            enable_o	=> enable_s
        );

        proce_inst : sconvGen_process
        generic map(
            PIXEL_SIZE  => IN_SIZE,
            IMAGE_WIDTH => IMAGE_WIDTH
        )
        port map(
            clk	        =>  clk_proc,
            reset_n	    =>  reset_n,
            enable	    =>  enable_s,
            in_data     =>  in_data,
            in_dv	    =>  in_dv,
            in_fv	    =>  in_fv,
            out1_data   =>  out1_data,
            out1_dv	    =>  out1_dv,
            out1_fv	    =>  out1_fv,
            out2_data   =>  out2_data,
            out2_dv	    =>  out2_dv,
            out2_fv	    =>  out2_fv,
            out3_data   =>  out3_data,
            out3_dv	    =>  out3_dv,
            out3_fv	    =>  out3_fv
        );

    end structural;
