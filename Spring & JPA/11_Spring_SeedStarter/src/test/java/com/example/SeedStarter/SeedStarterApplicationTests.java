package com.example.SeedStarter;

import com.example.SeedStarter.entity.SeedStarter;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class SeedStarterApplicationTests {

	@Test
	void contextLoads() {
		SeedStarter seedStarter = new SeedStarter();
		seedStarter.setCovered(false);
	}

}
